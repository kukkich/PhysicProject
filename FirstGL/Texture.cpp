//#define _USE_MATH_DEFINES
//#include <cmath>
//#include <glut.h>
//#include <iostream>
//#include <Windows.h>
//#include "Camera.h"
//
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//#pragma comment (lib, "opengl32.lib")
//
//float WinWid = 600, WinHei = 600;
//Camera camera = Camera(0, 0, 1.7, 0, 0);
//HWND hwnd;
//float theta = 0;
//unsigned int texture;
//
//float vertex[] = {
//	-1,-1,0,
//	1,-1,0,
//	1,1,0,
//	-1,1,0
//};
//
//float texCoord[] = { 0,1, 1,1, 1,0, 0, };
//
//
//
//void Game_Init()
//{
//	int width, height, cnt;
//	unsigned char *data = stbi_load("Billi.png", &width, &height, &cnt, 0);
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
//void Game_Show()
//{
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//
//	glColor3f(1, 1, 1);
//	glPushMatrix();
//	{
//		glEnableClientState(GL_VERTEX_ARRAY);
//		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//
//		glVertexPointer(3, GL_FLOAT, 0, vertex);
//		glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
//		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//
//		glDisableClientState(GL_VERTEX_ARRAY);
//		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//	}
//	glPopMatrix();
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
//void timer(int value)  {
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
//	
//	glEnable(GL_DEPTH_TEST);
//
//	Game_Init();
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
//		Game_Show();
//
//	}
//	glPopMatrix();
//
//	glutSwapBuffers();
//
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