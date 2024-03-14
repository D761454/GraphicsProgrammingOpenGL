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
	DrawTriangleAll();
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
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.75, 0.5); // t
		glVertex2f(-0.33, 0); // b r
		glVertex2f(-1, 0); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(0, 0.75); // t
		glVertex2f(0.2, 0); // b r
		glVertex2f(-0.2, 0); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
		glVertex2f(0.665, 0.75); // t
		glVertex2f(1, 0); // b r
		glVertex2f(0.33, 0); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.8, 0); // t
		glVertex2f(-0.33, -1); // b r
		glVertex2f(-1, -1); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(-0.33, 0); // t
		glVertex2f(0.33, -1); // b r
		glVertex2f(-0.33, -1); // b l
		glEnd(); // end drawing
	}

	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
		glVertex2f(0.33, -0.5); // t
		glVertex2f(1, -1); // b r
		glVertex2f(0.5, -1); // b l
		glEnd(); // end drawing
	}
}

HelloGL::~HelloGL(void) {

}