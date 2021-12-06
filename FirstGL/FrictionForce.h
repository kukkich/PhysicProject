#pragma once
#include "Force.h"
class FrictionForce :
    public Force
{
public:
    FrictionForce(glm::vec3 value);
    FrictionForce(float x=0, float y=0, float z=0);

    void Apply(PhysicalObject* target) override;
};

