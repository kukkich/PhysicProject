#include "Physic.h"


Rectangle::Rectangle(glm::vec3 position, float length, float width)
	: Shape(position)
{
	_length = length;
	_width = width;
}

void Rectangle::Draw()
{
	//TODO Сделать нормали для теней
	glPushMatrix();
	Shape::TranslateToPosition();

	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex2f(0, 0);
		glVertex2f(_length, 0);
		glVertex2f(_length, _width);
		glVertex2f(0, _width);
	}
	glEnd();
	glPopMatrix();
}

float Rectangle::DimensionalMeasure()
{
	return _width * _length;
}

float Rectangle::getLenght() const
{
	return _length;
}


float Rectangle::getWidth() const
{
	return _width;
}

