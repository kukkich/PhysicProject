//#define _USE_MATH_DEFINES
//#include <cmath>
//#include <glut.h>
//#include <iostream>
//#include <Windows.h>
//#include "Camera.h"
//#pragma comment (lib, "opengl32.lib")
//
//float WinWid = 600, WinHei = 600;
//Camera camera = Camera(0, 0, 1.7, 0, 0);
//HWND hwnd;
//float theta = 0;
//float vertex[] = { -1,-1,0, 1,-1,0, 1,1,0, -1,1,0 };
//float normal[] = { -1,-1,3, 1,-1,3, 1,1,3, -1,1,3 };
//float cube_vertex[] = {
//	1,1,0,	1,1,1,
//	-1,1,1,	-1,1,0,
//	-1,-1,0,	-1,-1,1,
//	1,-1,1,		1,-1,0
//};
//float cube_normal[] = {
//	1, 0, 0,
//	1, 0, 0,
//	0, 0, 1,
//	0, 0, 1,
//
//};
//
//float colors[] = {
//	1,0,0,
//	0,1,0,
//	0,0,1,
//	1,1,0,
//
//	1,0,0,
//	0,1,0,
//	0,0,1,
//	1,1,0
//};
//
////GLuint cube_index[] = {
////	0,1,2, 3,
////	2,3,4,5,
////	4,5,6,7,
////	6,7,0,1
////};
//
//GLuint cube_index[] = {
//	0, 1, 2, 3,
//	0, 3,4, 7,
//	0, 1, 6, 7
//};
//
//void Draw_cube()
//{
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);
//	glEnableClientState(GL_NORMAL_ARRAY);
//	{
//		glVertexPointer(3, GL_FLOAT, 0, &cube_vertex);
//		glColorPointer(3, GL_FLOAT, 0, colors);
//		glNormalPointer(GL_FLOAT, 0, cube_normal);
//
//		glDrawArrays(GL_QUADS, 0, 4);
//
//	}
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_COLOR_ARRAY);
//	glDisableClientState(GL_NORMAL_ARRAY);
//
//
//
//}
//
//void Draw()
//{
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_NORMAL_ARRAY);
//	{
//		glVertexPointer(3, GL_FLOAT, 0, vertex);
//		glNormalPointer(GL_FLOAT, 0, normal);
//		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//	}
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_NORMAL_ARRAY);
//
//}
//
//void Player_Move()
//{
//	const int forward = GetKeyState('W') < 0 ? 1 : (GetKeyState('S') < 0 ? -1 : 0);
//	const int right = GetKeyState('D') < 0 ? 1 : (GetKeyState('A') < 0 ? -1 : 0);
//	camera.MoveDirection(forward, right, 0.1);
//	camera.AutoMoveByMouse(400, 400, 0.2);
//}
//
//void timer(int value) {
//	glutPostRedisplay();
//	glutTimerFunc(30, timer, 0);
//}
//
//void init() {
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.2, 1000);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glEnable(GL_DEPTH_TEST);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_NORMALIZE);
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
//
//		glPushMatrix();
//		{
//			glRotatef(theta, 1, 0, 0);
//			float position[] = { 0,0,1,0 };
//			glLightfv(GL_LIGHT0, GL_POSITION, position);
//
//			glTranslatef(0, 1, 1);
//			glScalef(0.2, 0.2, 0.2);
//			glColor3f(1, 1, 1);
//			Draw();
//		}
//		glPopMatrix();
//		glColor3f(0, 1, 0);
//		Draw();
//		Draw_cube();
//
//
//	}
//	glPopMatrix();
//
//	glutSwapBuffers();
//
//	theta += 1;
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
//	//glutReshapeFunc(WndResize);
//	glutMotionFunc([](int x, int y) {ShowCursor(FALSE); });
//	glutPassiveMotionFunc([](int x, int y) {ShowCursor(FALSE); });
//
//	init();
//
//	glutMainLoop();
//}