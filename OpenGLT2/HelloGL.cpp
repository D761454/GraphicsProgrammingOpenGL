#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(16*50, 9*50);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display); // call back function
	glutMainLoop();
}

void HelloGL::Display() {
	// drawing code
	glClear(GL_COLOR_BUFFER_BIT); // clear scene
	DrawHexagon();
	glFlush(); // flush scene to graphics card
}

void HelloGL::DrawPolygon() {
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.75, 0.5); // top left
		glVertex2f(0.75, 0.5); // top right
		glVertex2f(0.75, -0.5); // bottom right
		glVertex2f(-0.75, -0.5); // bottom left
		glEnd(); // end drawing
	}
}

void HelloGL::DrawTriangle1() {
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glVertex2f(-0.25, 0.5); // t
		glVertex2f(0.75, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
}

void HelloGL::DrawTriangle2() {
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.5, 0.75); // t
		glVertex2f(-0.25, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
}

void HelloGL::DrawTriangle3() {
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.25, 0.75); // t
		glVertex2f(0.25, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
}

void HelloGL::DrawTriangle4() {
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.5, 0.75); // t
		glVertex2f(0.25, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
}

void HelloGL::DrawTriangle5() {
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.75, 0.75); // t
		glVertex2f(0.00, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
}

void HelloGL::DrawTriangle6() {
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.825, 0.75); // t
		glVertex2f(0.5, -0.5); // b r
		glVertex2f(-0.65, -0.5); // b l
		glEnd(); // end drawing
	}
}

void HelloGL::DrawTriangleAll() {
	glBegin(GL_POLYGON); // scalene
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.75, 0.5); // t
		glVertex2f(-0.33, 0); // b r
		glVertex2f(-1, 0); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // isoceles
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(0, 0.75); // t
		glVertex2f(0.2, 0); // b r
		glVertex2f(-0.2, 0); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // equilateral
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
		glVertex2f(0.665, 0.75); // t
		glVertex2f(1, 0); // b r
		glVertex2f(0.33, 0); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // acute
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.8, 0); // t
		glVertex2f(-0.33, -1); // b r
		glVertex2f(-1, -1); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // right angle
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(-0.33, 0); // t
		glVertex2f(0.33, -1); // b r
		glVertex2f(-0.33, -1); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // obtuse
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
		glVertex2f(0.33, -0.5); // t
		glVertex2f(1, -1); // b r
		glVertex2f(0.5, -1); // b l
		glEnd(); // end drawing
	}
}

void HelloGL::DrawHexagon() {
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(-0.25, 0.5); // t l
		glVertex2f(0.25, 0.5); // t r
		glVertex2f(-0.5, 0); // m l
		glVertex2f(0.5, 0); // m r
		glVertex2f(0.25, -0.5); // b r
		glVertex2f(-0.25, -0.5); // b l
		glEnd(); // end drawing
	}
}

HelloGL::~HelloGL(void) {

}