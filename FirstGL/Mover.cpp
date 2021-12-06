#include "Physic.h"

Mover::Mover(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration)
	: WorldObject(position)
{
	Velocity = velocity;
	Acceleration = acceleration;
}

void Mover::Update()
{
	Position += Velocity;
	Velocity += Acceleration;
	Acceleration = { 0,0,0 };
}
