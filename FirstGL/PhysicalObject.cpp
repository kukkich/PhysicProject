#pragma once
#include "Physic.h"

PhysicalObject::PhysicalObject(
	const Cylinder& form, Material matter,
	glm::vec3 velocity,
	glm::vec3 acceleration
)
	: Mover(form.Position, velocity, acceleration)
{
	_form = form;
	_form.Position = { 0,0,0 },
	Matter = matter;
	_mass = Matter.Density * _form.DimensionalMeasure();
}

PhysicalObject::PhysicalObject(
	glm::vec3 position,
	float height, float radius,
	Material matter, 
	glm::vec3 velocity,
	glm::vec3 acceleration
)
	: Mover(position, velocity, acceleration)
{
	_form = Cylinder({ 0,0,0 }, height, radius);
	Matter = matter;
	_mass = Matter.Density * _form.DimensionalMeasure();
	Momentum = _mass * Velocity;
}

void PhysicalObject::ApplyForce(const Force* force)
{
	glm::vec3 f = force->getValue() / _mass;
	Acceleration += f;
}

bool PhysicalObject::CheckCollision(const PhysicalObject& object) const
{
	return getRadius() + object.getRadius() >=
		sqrtf(
			powf(object.Position.x - Position.x, 2) +
			powf(object.Position.y - Position.y, 2) 
		);
}

void PhysicalObject::CollideWith(PhysicalObject& object)
{
	glm::vec3 distance = object.Position - Position;
	glm::vec3 velocityDiff = object.Velocity - Velocity;
	float coef = abs(
		2 * glm::dot(distance, velocityDiff) / 
		((object.getMass() + getMass()) * glm::dot(distance, distance))
	);
	Velocity = Velocity - distance * object.getMass() * coef;
	object.Velocity = object.Velocity + distance * getMass() * coef;

}

void PhysicalObject::Update()
{
	Mover::Update();
	Momentum = Velocity * _mass;
}

void PhysicalObject::Draw()
{
	glPushMatrix();
	glTranslatef(Position.x, Position.y, Position.z);
	_form.Draw();
	glPopMatrix();
}

float PhysicalObject::getRadius() const
{
	return _form.getRadius();
}

float PhysicalObject::getMass() const
{
	return _mass;
}
