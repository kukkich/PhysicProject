#include "Physic.h"


Triangle::Triangle(glm::vec3 position, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3)
	: Shape(position)
{
	_vertices[0] = v1;
	_vertices[1] = v2;
	_vertices[2] = v3;
}

void Triangle::Draw()
{
	throw std::exception("Triangle.Draw() is not implemented");
}

float Triangle::DimensionalMeasure()
{
	throw std::exception("Triangle.DimensionalMeasure() is not implemented");
}
