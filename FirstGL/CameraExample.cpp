//#define _USE_MATH_DEFINES
//#include <cmath>
//#include <glut.h>
//#include <Windows.h>
//#pragma comment (lib, "opengl32.lib")
//
//float WinWid = 900, WinHei = 800;
//
//float vert[] = { -1,1,0, 1,1,0, 1,-1,0, -1,-1,0 };
//float xAngle = 0;
//float zAngle = 0;
//float zPosition = 0;
//bool rotate = true;
//POINTFLOAT pos = { 0, 0 };
//
//
//void ShowWorld()
//{
//	glEnableClientState(GL_VERTEX_ARRAY);
//
//	glVertexPointer(3, GL_FLOAT, 0, &vert);
//	for (int i = -5; i < 5; i++)
//	{
//		for (int j = -5; j < 5; ++j)
//		{
//			glPushMatrix();
//
//			if ((i + j) % 2 == 0) glColor3f(0, 0.5, 0);
//			else glColor3f(1, 1, 1);
//			glTranslatef(i * 2, j * 2, 0);
//			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//			glPopMatrix();
//		}
//	}
//	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//
//	glDisableClientState(GL_VERTEX_ARRAY);
//}
//void MoveCamera()
//{
//	if (GetKeyState(VK_UP) < 0) xAngle = ++xAngle > 180 ? 180 : xAngle;
//	if (GetKeyState(VK_DOWN) < 0) xAngle = --xAngle < 0 ? 0 : xAngle;
//	if (GetKeyState(VK_LEFT) < 0) zAngle += 3;
//	if (GetKeyState(VK_RIGHT) < 0) zAngle -= 3;
//
//	float angle = -zAngle / 180 * M_PI;
//	float speed = 0;
//	if (GetKeyState('W') < 0) speed = 0.2;
//	if (GetKeyState('S') < 0) speed = -0.2;
//	if (GetKeyState('A') < 0) { speed = 0.2; angle -= M_PI_2; }
//	if (GetKeyState('D') < 0) { speed = 0.2; angle += M_PI_2; }
//	if (GetKeyState(VK_SPACE) < 0) { zPosition += 0.04; }
//	if (GetKeyState(VK_SHIFT) < 0) { zPosition -= 0.04; }
//	if (GetKeyState(VK_TAB)) rotate = !rotate;
//	if (speed)
//	{
//		pos.x += sin(angle) * speed;
//		pos.y += cos(angle) * speed;
//	}
//
//	glRotatef(-xAngle, 1, 0, 0);
//	glRotatef(-zAngle, 0, 0, 1);
//	glTranslatef(-pos.x, -pos.y, -4 - zPosition);
//}
//
//void timer(int value) {
//	glutPostRedisplay();
//	glutTimerFunc(40, timer, 0);
//}
//
//
//void init() {
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	glMatrixMode(GL_PROJECTION);
//	glFrustum(-1, 1, -1, 1, 2, 80);
//	glEnable(GL_DEPTH_TEST);
//}
//float angle = 0;
//int z = 2.3;
//void draw() {
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glPushMatrix();
//	MoveCamera();
//	glRotatef(angle, 0, 0, 1);
//	angle += (int)rotate;
//	ShowWorld();
//	glPointSize(10);
//	glBegin(GL_TRIANGLE_STRIP);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.5, 0.5, 0 + z);
//	glColor3f(0, 1, 0);
//	glVertex3f(-0.5, 0.5, 0 + z);
//	glColor3f(0.3, 0, 1);
//	glVertex3f(0, -0.5, 0 + z);
//	glColor3f(0.7, 0.1, 0.9);
//	glVertex3f(0, 0, 1 + z);
//	glColor3f(1, 0, 0);
//	glVertex3f(0.5, 0.5, -0 + z);
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, 1 + z);
//	glColor3f(1, 1, 0);
//	glVertex3f(-0.5, 0.5, -0 + z);
//	glEnd();
//
//
//	glPopMatrix();
//
//
//
//	glutSwapBuffers();
//}
//
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
//
//	glutDisplayFunc(draw);
//	glutTimerFunc(165, timer, 0);
//
//	init();
//
//	glutMainLoop();
//}