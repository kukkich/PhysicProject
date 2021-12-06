//#define _USE_MATH_DEFINES
//#include <cmath>
//#include <glut.h>
//#include <iostream>
//#include <Windows.h>
//#include "Camera.h"
//#pragma comment (lib, "opengl32.lib")
//
//float WinWid = 1000, WinHei = 900;
//Camera camera = Camera(0, 0, 1.7, 0, 0);
//HWND hwnd;
//
//void WndResize(int x, int y)
//{
//	glViewport(0, 0, x, y);
//	float k = x / static_cast<float>(y);
//	float sz = 0.1;
//	glLoadIdentity();
//	glFrustum(-k * sz, k * sz, -sz, sz, sz * 2, 100);
//}
//
//void Player_Move()
//{
//	const int forward = GetKeyState('W') < 0 ? 1 : (GetKeyState('S') < 0 ? -1 : 0);
//	const int right = GetKeyState('D') < 0 ? 1 : (GetKeyState('A') < 0 ? -1 : 0);
//	camera.MoveDirection(forward, right, 0.5);
//	camera.AutoMoveByMouse(400, 400, 5);
//
//	camera.z = Map_GetHeight(camera.x, camera.y) + 1.7;
//}
//
//void timer(int value) {
//	glutPostRedisplay();
//	glutTimerFunc(30, timer, 0);
//}
//
//void init() {
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	glMatrixMode(GL_PROJECTION);
//	glEnable(GL_DEPTH_TEST);
//
//
//	RECT rct;
//	GetClientRect(hwnd, &rct);
//	WndResize(rct.right, rct.bottom);
//
//	Map_Init();
//
//}
//
//void draw() {
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glPushMatrix();
//	{
//		if (GetForegroundWindow() == hwnd) Player_Move();
//		camera.Apply();
//
//		Map_Show();
//	}
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//
//
//	glutInitWindowSize(WinWid, WinHei);
//	glutInitWindowPosition(400, 150);
//	glutCreateWindow("WebWindow");
//
//	hwnd = FindWindow(0, L"WebWindow");
//	std::cout << (hwnd ? "Good" : "Bad") << std::endl;
//
//	glutDisplayFunc(draw);
//	glutTimerFunc(165, timer, 0);
//	glutReshapeFunc(WndResize);
//	glutMotionFunc([](int x, int y) {ShowCursor(FALSE); });
//	glutPassiveMotionFunc([](int x, int y) {ShowCursor(FALSE); });
//
//	init();
//
//	glutMainLoop();
//}