#pragma once
#include "Shape.h"
class Parallelepiped :
    public Shape
{
public:
    Parallelepiped(glm::vec3 position, glm::vec3 sizes);
    Parallelepiped(glm::vec3 position, float length, float width, float height);
    void Draw() override;
    float DimensionalMeasure() override;

private:

    float _length;
    float _width;
    float _height;
};

