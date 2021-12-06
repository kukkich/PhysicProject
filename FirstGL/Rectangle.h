#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
    Rectangle(glm::vec3 position, float height, float width);
    void Draw() override;
    float DimensionalMeasure() override;

private:
    float _height;
    float _width;
};

