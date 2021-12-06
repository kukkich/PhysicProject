//#define _USE_MATH_DEFINES
//#include <cmath>
//#include <glut.h>
//#include <iostream>
//#include <Windows.h>
//#include "Camera.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#pragma comment (lib, "opengl32.lib")
//
//float WinWid = 900, WinHei = 800;
//Camera camera = Camera(0, 0, 1.7, 0, 0);
//HWND hwnd;
//float theta = 0;
//float vertex[] = { -1,-1,1, 1,-1,1, 1,1,1, -1,1,1 };
//float normal[] = { -1,-1,1, 1,-1,1, 1,1,1, -1,1,1 };
//float texCoord[] = { 0,1, 1,1, 1,0, 0, };
//unsigned int texture;
//
//
//void DrawBilli()
//{
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_NORMAL_ARRAY);
//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//	{
//		glVertexPointer(3, GL_FLOAT, 0, vertex);
//		glNormalPointer(GL_FLOAT, 0, normal);
//		glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
//
//		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//	}
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_NORMAL_ARRAY);
//	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//	glDisable(GL_TEXTURE_2D);
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
//
//		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//	}
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glDisableClientState(GL_NORMAL_ARRAY);
//
//
//}
//
//
//void DrawCube()
//{
//
//	glPushMatrix();
//	{
//		glScalef(0.4, 0.4, 0.4);
//		DrawBilli();
//		for (int i = 0; i < 4; ++i)
//		{
//			glRotatef(90, 1, 0, 0);
//			DrawBilli();
//		}
//
//		glRotatef(90, 0, 1, 0);
//		DrawBilli();
//		glRotatef(180, 0, 1, 0);
//		DrawBilli();
//	}
//	glPopMatrix();
//}
//
//void Billi_Init()
//{
//	int width, height, cnt;
//	unsigned char* data = stbi_load("Billi.png", &width, &height, &cnt, 0);
//
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	{
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glTexImage2D(GL_TEXTURE_2D,
//			0, GL_RGB, width, height,
//			0, GL_RGB, GL_UNSIGNED_BYTE, data
//		);
//	}
//	glBindTexture(GL_TEXTURE_2D, 0);
//	stbi_image_free(data);
//}
//
//void Player_Move()
//{
//	const int forward = GetKeyState('W') < 0 ? 1 : (GetKeyState('S') < 0 ? -1 : 0);
//	const int right = GetKeyState('D') < 0 ? 1 : (GetKeyState('A') < 0 ? -1 : 0);
//	camera.MoveDirection(forward, right, 0.05);
//	camera.AutoMoveByMouse(400, 400, 0.2);
//}
//
//void timer(int value) {
//	glutPostRedisplay();
//	glutTimerFunc(20, timer, 0);
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
//
//
//
//	Billi_Init();
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
//			glRotatef(360 * pow(sin(theta / 10), 3), 0, 0, 1);
//			glRotatef(theta, 1, 0, 0);
//			float position[] = { 0,0,1,0 };
//			glLightfv(GL_LIGHT0, GL_POSITION, position);
//
//			glTranslatef(0, 0, 1);
//			glScalef(0.1, 0.1, 0.1);
//			glColor3f(1, 1, 1);
//			Draw();
//		}
//		glPopMatrix();
//		glColor3f(1, 1, 1);
//		DrawCube();
//
//
//	}
//	glPopMatrix();
//
//	glutSwapBuffers();
//
//	theta += 0.2;
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
//	glutTimerFunc(20, timer, 0);
//	//glutReshapeFunc(WndResize);
//	glutMotionFunc([](int x, int y) {ShowCursor(FALSE); });
//	glutPassiveMotionFunc([](int x, int y) {ShowCursor(FALSE); });
//
//	init();
//
//	glutMainLoop();
//}