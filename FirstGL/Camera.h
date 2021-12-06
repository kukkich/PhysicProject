#pragma once

class Camera
{
public:
	Camera(float x, float y, float z, float x_angle=0, float z_angle=0);
	void Apply() const;
	void Rotation(float x_angle, float z_angle);
	void AutoMoveByMouse(int center_x, int center_y, float speed);
	void MoveDirection(int forwardDirection, int rightDirection, float sped);

	float x;
	float y;
	float z;
	float x_angle;
	float z_angle;
};
