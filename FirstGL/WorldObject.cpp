#include "Physic.h"


WorldObject::WorldObject(float x, float y, float z)
{
	Position = glm::vec3(x, y, z);
}

WorldObject::WorldObject(glm::vec3 pos)
{
	Position = pos;
}

