#define _USE_MATH_DEFINES
#include <cmath>
#include <glut.h>
#include <iostream>
#include "Physic.h"
#include <Windows.h>
#include "Camera.h"
#include <glm/glm.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#pragma comment (lib, "opengl32.lib")


float WinWid = 900, WinHei = 800;
Camera camera = Camera(-0.5, 1.7, 1.7, 45, 0);
HWND hwnd;
float theta = 0;
float vertex[] = { -1,-1,1, 1,-1,1, 1,1,1, -1,1,1 };
float normal[] = { -1,-1,1, 1,-1,1, 1,1,1, -1,1,1 };
float texCoord[] = { 0,1, 1,1, 1,0, 0, };
unsigned int texture;

glm::vec3 pos(1.3, 1.3, 2.6);

Material Kirpich;

PhysicalObject *obj_1;
PhysicalObject *obj_2;

Scene* scene = nullptr;

void Scene_Init()
{
	Kirpich = Material(0.05);
	obj_1 = new PhysicalObject(Cylinder({ 0,0,0 }, 0.2f, 1.0f), Kirpich, { 0.05, 0.1, 0 });
	obj_2 = new PhysicalObject(Cylinder({ 0,0,0 }, 0.5f, 0.3f), Kirpich, { 0.91, -0.07, 0 });

	scene = new Scene(pos, obj_1, obj_2, {16, 9, 1.2}, 0.2f, 0.001f);
}

void DrawSqare()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	{
		glVertexPointer(3, GL_FLOAT, 0, vertex);
		glNormalPointer(GL_FLOAT, 0, normal);

		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);


}

void DrawCube()
{
	
	glPushMatrix();
	{
		glScalef(0.4, 0.4, 0.4);
		DrawSqare();
		for (int i = 0; i < 4; ++i)
		{
			glRotatef(90, 1, 0, 0);
			DrawSqare();
		}

		glRotatef(90, 0, 1, 0);
		DrawSqare();
		glRotatef(180, 0, 1, 0);
		DrawSqare();
	}
	glPopMatrix();
}

void Player_Move()
{
	const int forward = GetKeyState('W') < 0 ? 1 : (GetKeyState('S') < 0 ? -1 : 0);
	const int right = GetKeyState('D') < 0 ? 1 : (GetKeyState('A') < 0 ? -1 : 0);
	const int vertical = GetKeyState(VK_SHIFT) < 0 ? -1 : (GetKeyState(VK_SPACE) < 0 ? 1 : 0);
	camera.MoveDirection(forward, right, 0.05);
	camera.AutoMoveByMouse(400, 400, 0.15);
	camera.z += vertical * 0.05;
}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(20, timer, 0);
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.2, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	Scene_Init();
}

void draw() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		if (GetForegroundWindow() == hwnd) Player_Move();

		camera.Apply();


		glPushMatrix();
		{
			glRotatef(360 * pow(sin(theta/10), 3), 0, 0, 1);
			//glRotatef(theta, 1, 0, 0);
			float position[] = { 0,-1,2,0 };
			glLightfv(GL_LIGHT0, GL_POSITION, position);

			glTranslatef(position[0], position[1], position[2]);
			glScalef(0.1, 0.1, 0.1);
			glColor3f(1, 1, 1);
			DrawSqare();
		}
		glPopMatrix();
		glColor3f(1, 1, 1);
		DrawCube();

		glScalef(0.2, 0.2, 0.2);
		scene->Update();
		scene->Draw();

		
	}
	glPopMatrix();

	glutSwapBuffers();

	theta += 0.2;
}

int main(int argc, char** argv) {
	
	cout << pos.r << " " << glm::length(pos) << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


	glutInitWindowSize(WinWid, WinHei);
	glutInitWindowPosition(400, 150);
	glutCreateWindow("WebWindow");

	hwnd = FindWindow(0, L"WebWindow");
	std::cout << (hwnd ? "Good" : "Bad") << std::endl;

	glutDisplayFunc(draw);
	glutTimerFunc(20, timer, 0);
	//glutReshapeFunc(WndResize);
	glutMotionFunc([](int x, int y) {ShowCursor(FALSE); });
	glutPassiveMotionFunc([](int x, int y) {ShowCursor(FALSE); });

	init();
	glutMainLoop();
}