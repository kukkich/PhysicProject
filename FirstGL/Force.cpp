#pragma once
#include "Physic.h"

Force::Force(glm::vec3 value)
{
	_value = value;
}
Force::Force(float x, float y, float z)
{
	_value = glm::vec3(x, y, z);
}
glm::vec3 Force::getValue() const
{
	return _value;
}
