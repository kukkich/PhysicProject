#pragma once
#include <glm/glm.hpp>
#include "PhysicalObject.h"

class Force
{
public:
	Force(glm::vec3 value);
	Force(float x=0, float y=0, float z=0);
	virtual void Apply(PhysicalObject* target) = 0;
private:
	glm::vec3 _value;
};

