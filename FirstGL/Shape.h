#pragma once
#include "WorldObject.h"
class Shape :
    public WorldObject
{
public:
    Shape(glm::vec3 position={0,0,0});
    virtual void Draw() = 0;
    virtual float DimensionalMeasure() = 0;
};
