#define _USE_MATH_DEFINES
#include <cmath>
#include <Windows.h>
#include <glut.h>
#include <glm/glm.hpp>

#include "MathTools.h"
#include "Camera.h"

#pragma comment (lib, "opengl32.lib")


Camera::Camera(float x, float y, float z, float x_angle, float z_angle)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->x_angle = x_angle;
	this->z_angle = z_angle;
}

void Camera::Apply() const
{
	glRotatef(-x_angle, 1, 0, 0);
	glRotatef(-z_angle, 0, 0, 1);
	glTranslatef(-x, -y, -z);
}

void Camera::Rotation(float x_angle, float z_angle)
{
	this->z_angle += z_angle;
	if (this->z_angle < 0) this->z_angle += 360;
	if (this->z_angle > 360) this->z_angle -= 360;
	this->x_angle += x_angle;
	if (this->x_angle < 0) this->x_angle = 0;
	if (this->x_angle > 180) this->x_angle = 180;
}

void Camera::AutoMoveByMouse(int center_x, int center_y, float speed)
{
	POINT cursor_position;
	POINT base = { center_x, center_y };
	GetCursorPos(&cursor_position);
	Rotation((base.y - cursor_position.y) * speed, (base.x - cursor_position.x) * speed);
	SetCursorPos(base.x, base.y);
}

void Camera::MoveDirection(int forwardDirection, int rightDirection, float speed)
{
	float angle = -this->z_angle / 180 * M_PI;
	if (forwardDirection > 0)
		angle += sign(rightDirection) * M_PI_4;
	else if (forwardDirection < 0)
		angle += M_PI - sign(rightDirection) * M_PI_4;
	else
	{
		angle += sign(rightDirection) * M_PI_2;
		if (!rightDirection) speed = 0;
	}
	this->x += sin(angle) * speed;
	this->y += cos(angle) * speed;
}


