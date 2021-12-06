#include "Physic.h"


Parallelepiped::Parallelepiped(glm::vec3 position, float length, float width, float height)
	: Rectangle(position, length, width)
{
	_height = height;
}

Parallelepiped::Parallelepiped(glm::vec3 position, glm::vec3 sizes)
	: Rectangle(position, sizes.x, sizes.y)
{
	_height = sizes.z;
}

void Parallelepiped::Draw()
{
	glPushMatrix();
	Shape::TranslateToPosition();

	glPushMatrix();
	{
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(_length, 0, 0);
			glVertex3f(_length, 0, _height);
			glVertex3f(0, 0, _height);
		} glEnd();
		glTranslatef(0, _width, 0);
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(_length, 0, 0);
			glVertex3f(_length, 0, _height);
			glVertex3f(0, 0, _height);
		} glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(_length, 0, 0);
			glVertex3f(_length, _width, 0);
			glVertex3f(0, _width, 0);
		} glEnd();
		glTranslatef(0, 0, _height);
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(_length, 0, 0);
			glVertex3f(_length, _width, 0);
			glVertex3f(0, _width, 0);
		} glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(0, _width, 0);
			glVertex3f(0, _width, _height);
			glVertex3f(0, 0, _height);
		} glEnd();
		glTranslatef(_length, 0, 0);
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex3f(0, 0, 0);
			glVertex3f(0, _width, 0);
			glVertex3f(0, _width, _height);
			glVertex3f(0, 0, _height);
		} glEnd();
	}
	glPopMatrix();

	glPopMatrix();
}

float Parallelepiped::DimensionalMeasure()
{
	return _length * _width * _height;
}
