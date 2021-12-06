#pragma once
#include "Shape.h"
class Triangle :
    public Shape
{
public:
	Triangle(
		glm::vec3 position,
		glm::vec3 v1,
		glm::vec3 v2,
		glm::vec3 v3
	);
	void Draw() override;
	float DimensionalMeasure() override;

private:
	glm::vec3 _vertices[3];
};

