#include "Physic.h"


Shape::Shape(glm::vec3 position)
	: WorldObject(position) {}

void Shape::TranslateToPosition() const
{
	glTranslatef(Position.x, Position.y, Position.z);
}
