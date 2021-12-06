#pragma once
#include "WorldObject.h"
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

