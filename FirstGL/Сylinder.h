#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"


class Cylinder : public Circle
{
public:
	Cylinder(glm::vec3 position = { 0,0,0 }, float height=1, float radius=1);
	void Draw() override;
	float DimensionalMeasure() override;
private:
	float _height;
	float _radius;
};