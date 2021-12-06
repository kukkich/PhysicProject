#pragma once
#include "Force.h"
#include "Mover.h"
#include "Ñylinder.h"
#include "Material.h"

class PhysicalObject :
	public Mover
{
public:

	PhysicalObject(
		Cylinder form, Material matter, float mass,
		glm::vec3 position = { 0,0,0 },
		glm::vec3 velocity = { 0,0,0 },
		glm::vec3 acceleration = { 0,0,0 }
	);

	void ApplyForce(Force* force);
	bool CheckCollision(Shape* object);
	void CollideWith(Shape* object);

	Material Matter;
	Cylinder Form;
	float Mass;
};
