#pragma once
#include "Shape.h"

class Circle :
    public Shape
{
public:
    Circle(glm::vec3 position, float radius);
    virtual void Draw() override;
    float DimensionalMeasure() override;
private:
    float _radius;
};

