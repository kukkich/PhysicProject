#include "Physic.h"


FrictionForce::FrictionForce(const PhysicalObject& target, const Ground& stirrer)
{
	glm::vec3 friction = target.Velocity;
	try
	{
		glm::normalize(friction);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
		friction = glm::vec3(0,0,0);
	}

	friction *= -1 * stirrer.getFrictionCoefficient() * target.getMass() * gravityConstant;
	_value = friction;
}

void FrictionForce::Apply(PhysicalObject* target)
{

	if (glm::length(target->Velocity) <= (glm::length(getValue() / target->getMass())) )
	{
		target->Velocity = glm::vec3(0, 0, 0);
		return;
	}
	cout << glm::length(target->Velocity) << " " << glm::length(getValue() / target->getMass()) << endl;
	target->ApplyForce(this);

}

FrictionForce::FrictionForce(glm::vec3 value)
	: Force(value){}

FrictionForce::FrictionForce(float x, float y, float z)
	: Force(x, y, z) {}
