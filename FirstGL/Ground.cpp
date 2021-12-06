#include "Physic.h"

Ground::Ground(glm::vec3 position, float length, float width, float frictionCoefficient)
	: Rectangle(position, length, width)
{
	_frictionCoefficient = frictionCoefficient;
}

void Ground::Frict(PhysicalObject& target) const
{
	FrictionForce friction = FrictionForce(target, *this);
	friction.Apply(&target);
}

float Ground::getFrictionCoefficient() const
{
	return _frictionCoefficient;
}
