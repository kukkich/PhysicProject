#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <glm/glm.hpp>
#include <glut.h>
#include <exception>
#include <vector>
#include <iostream>
using namespace std;
#pragma comment (lib, "opengl32.lib")

constexpr float gravityConstant = 3;

class Force;
class Ground;

class WorldObject
{
public:
	WorldObject(glm::vec3 pos = { 0,0,0 });
	WorldObject(float x = 0, float y = 0, float z = 0);
	glm::vec3 Position;
};

class Mover :
	public WorldObject
{
public:

	Mover(
		glm::vec3 position = { 0,0,0 },
		glm::vec3 velocity = { 0,0,0 },
		glm::vec3 acceleration = { 0,0,0 }
	);
	virtual void Update();

	glm::vec3 Velocity;
	glm::vec3 Acceleration;
};

class Shape :
	public WorldObject
{
public:
	Shape(glm::vec3 position = { 0,0,0 });
	virtual void Draw() = 0;
	virtual float DimensionalMeasure() = 0;
	void TranslateToPosition() const;
};

class Triangle :
	public Shape
{
public:
	Triangle(
		glm::vec3 position,
		glm::vec3 v1,
		glm::vec3 v2,
		glm::vec3 v3
	);
	void Draw() override;
	float DimensionalMeasure() override;

private:
	glm::vec3 _vertices[3];
};

class Circle :
	public Shape
{
public:
	Circle(glm::vec3 position, float radius);
	virtual void Draw() override;
	float DimensionalMeasure() override;
	static int Segments;
	float getRadius() const;
protected:
	float _radius;
};

class Rectangle :
	public Shape
{
public:
	Rectangle(glm::vec3 position = { 0,0,0 }, float length = 1, float width = 1);
	void Draw() override;
	float DimensionalMeasure() override;

	float getLenght() const;
	float getWidth() const;

protected:
	float _length;
	float _width;
};

class Cylinder : public Circle
{
public:
	Cylinder(glm::vec3 position = { 0,0,0 }, float height = 1, float radius = 1);
	void Draw() override;
	float DimensionalMeasure() override;
private:

	void DrawBorder() ;
	float _height;
};

class Parallelepiped :
	public Rectangle
{
public:
	Parallelepiped(glm::vec3 position = {0,0,0}, glm::vec3 sizes={1,1,1});
	Parallelepiped(glm::vec3 position, float length, float width, float height);
	void Draw() override;
	float DimensionalMeasure() override;

private:
	float _height;
};

class Material
{
public:
	Material(float density = 0);

	float Density;
};

class PhysicalObject :
	public Mover
{
public:

	PhysicalObject(
		const Cylinder& form = Cylinder(), Material matter = Material(),
		glm::vec3 velocity = { 0,0,0 },
		glm::vec3 acceleration = { 0,0,0 }
	);
	PhysicalObject(
		glm::vec3 position = { 0,0,0 },
		float height = 1, float radius = 1,
		Material matter = Material(),
		glm::vec3 velocity = { 0,0,0 },
		glm::vec3 acceleration = { 0,0,0 }
	);
	void ApplyForce(const Force* force);
	bool CheckCollision(const PhysicalObject& object) const;
	void CollideWith(PhysicalObject& object);
	void Draw();
	void Update() override;
	float getRadius() const;
	float getMass() const;

	Material Matter;
	glm::vec3 Momentum;
private:
	Cylinder _form;
	float _mass;

};

class Force
{
public:
	virtual void Apply(PhysicalObject* target) = 0;
	glm::vec3 getValue() const;
protected:
	Force(glm::vec3 value);
	Force(float x = 0, float y = 0, float z = 0);
	glm::vec3 _value;
};

class FrictionForce :
	public Force
{
public:
	FrictionForce(const PhysicalObject& target, const Ground& stirrer);
	void Apply(PhysicalObject* target) override;
private:
	FrictionForce(glm::vec3 value);
	FrictionForce(float x = 0, float y = 0, float z = 0);

};

class Ground : public Rectangle
{
public:
	Ground(glm::vec3 position = { 0,0,0 }, float length = 1, float width = 1, float frictionCoefficient = 0.01);
	void Frict(PhysicalObject& target) const;
	float getFrictionCoefficient() const;
private:
	float _frictionCoefficient;
};

class Scene
{
public:
	Scene(
		glm::vec3 position,
		PhysicalObject* first, PhysicalObject* second,
		glm::vec3 sizes, float borderSize, float frictionCoefficient=0.01f
	);
	void Draw();
	void Update();
private:
	void Edges(PhysicalObject* object) const;

	PhysicalObject* _firstObject;
	PhysicalObject* _secondObject;
	Ground _ground;
	std::vector<Parallelepiped> _border;
};