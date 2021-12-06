#include "Physic.h"


Cylinder::Cylinder(glm::vec3 position, float height, float radius)
	:Circle(position, radius)
{
	_height = height;
}
void Cylinder::Draw()
{
	//TODO Сделать нормали для теней
	glPushMatrix();
	{
		glColor3ub(5, 113, 108);

		Circle::Draw();
		glTranslatef(0, 0, _height);

		Circle::Draw();
	}
	glPopMatrix();
	glColor3ub(3, 17, 99);
	DrawBorder();
}

void Cylinder::DrawBorder()
{
	float x, y, xNext, yNext, angle, angleNext;

	glPushMatrix();
	Shape::TranslateToPosition();

	glBegin(GL_QUADS);
	for (int i = 0; i < Segments; i++) {
		{
			angle = (float)i / (float)Segments * M_PI * 2.0f;
			angleNext = (float)(i + 1) / (float)Segments * M_PI * 2.0f;

			x = _radius * cos(angle); xNext = _radius * cos(angleNext);
			y = _radius * sin(angle); yNext = _radius * sin(angleNext);

			glVertex3f(x, y, 0);
			glVertex3f(x, y, _height);
			glVertex3f(xNext, yNext, _height);
			glVertex3f(xNext, yNext, 0);
		}
	}
	glEnd();
	glPopMatrix();
}

float Cylinder::DimensionalMeasure()
{
	return _height * Circle::DimensionalMeasure();
}