#pragma once
#include <glm/glm.hpp>
#include <exception>

class WorldObject
{
public:
	WorldObject(glm::vec3 pos={0,0,0});
	WorldObject(float x=0, float y=0, float z=0);
	glm::vec3 Position;
};

