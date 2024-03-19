#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(16*50, 9*50);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display); // call back function
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();
}

void HelloGL::Display() {
	// drawing code
	glClear(GL_COLOR_BUFFER_BIT); // clear scene

	DrawTriangleAll();

	glFlush(); // flush scene to graphics card
}

void HelloGL::DrawTriangleBase(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b, float a) {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(r, g, b, a);
		glVertex2f(x1, y1); // t
		glVertex2f(x2, y2); // b r
		glVertex2f(x3, y3); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawPolygon() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.75, 0.5); // top left
		glVertex2f(0.75, 0.5); // top right
		glVertex2f(0.75, -0.5); // bottom right
		glVertex2f(-0.75, -0.5); // bottom left
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawTriangle1() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glVertex2f(-0.25, 0.5); // t
		glVertex2f(0.75, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawTriangle2() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.5, 0.75); // t
		glVertex2f(-0.25, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawTriangle3() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.25, 0.75); // t
		glVertex2f(0.25, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawTriangle4() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.5, 0.75); // t
		glVertex2f(0.25, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawTriangle5() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.75, 0.75); // t
		glVertex2f(0.00, -0.5); // b r
		glVertex2f(-0.75, -0.5); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawTriangle6() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // begin drawing
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.825, 0.75); // t
		glVertex2f(0.5, -0.5); // b r
		glVertex2f(-0.65, -0.5); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawTriangleAll() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // scalene
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, 0.5); // t
		glVertex2f(-0.33, 0); // b r
		glVertex2f(-1, 0); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // isoceles
	{
		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.75); // t
		glVertex2f(0.2, 0); // b r
		glVertex2f(-0.2, 0); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // equilateral
	{
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.665, 0.75); // t
		glVertex2f(1, 0); // b r
		glVertex2f(0.33, 0); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // acute
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.8, 0); // t
		glVertex2f(-0.33, -1); // b r
		glVertex2f(-1, -1); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // right angle
	{
		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(-0.33, 0); // t
		glVertex2f(0.33, -1); // b r
		glVertex2f(-0.33, -1); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); // obtuse
	{
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.33, -0.5); // t
		glVertex2f(1, -1); // b r
		glVertex2f(0.5, -1); // b l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawHexagon() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.25, 0.75); // t l
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
		glVertex2f(0.25, 0.75); // t r
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
		glVertex2f(0.5, 0); // m r
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(0.25, -0.75); // b r
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(-0.25, -0.75); // b l
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.5, 0); // m l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawPentagon() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(0, 0.6); // t l
		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
		glVertex2f(0.4, 0); // m r
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(0.25, -0.75); // b r
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f(-0.25, -0.75); // b l
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.4, 0); // m l
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::Draw3DCube() {
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); 
	{
		// top
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glVertex2f(0, 0.75);
		// r
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glVertex2f(0.5, 0.375);
		// b
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glVertex2f(0, 0);
		// l
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glVertex2f(-0.5, 0.375);
		glEnd();
	}
	glBegin(GL_POLYGON);
	{
		// top
		glColor4f(0.75f, 0.75f, 0.75f, 0.5f);
		glVertex2f(0.5, 0.375);
		// r
		glColor4f(0.75f, 0.75f, 0.75f, 0.5f);
		glVertex2f(0.5, -0.5);
		// b
		glColor4f(0.75f, 0.75f, 0.75f, 0.5f);
		glVertex2f(0, -0.875);
		// l
		glColor4f(0.75f, 0.75f, 0.75f, 0.5f);
		glVertex2f(0, 0);
		glEnd();
	}
	glBegin(GL_POLYGON);
	{
		// top
		glColor4f(0.25f, 0.25f, 0.25f, 0.5f);
		glVertex2f(-0.5, 0.375);
		// r
		glColor4f(0.25f, 0.25f, 0.25f, 0.5f);
		glVertex2f(-0.5, -0.5);
		// b
		glColor4f(0.25f, 0.25f, 0.25f, 0.5f);
		glVertex2f(0, -0.875);
		// l
		glColor4f(0.25f, 0.25f, 0.25f, 0.5f);
		glVertex2f(0, 0);
		glEnd();
	}
	glPopMatrix();
}

void HelloGL::Update() {
	rotation += 0.5f;

	if (rotation >= 360.0f) {
		rotation = 0.0f;
	}

	glutPostRedisplay();
}

HelloGL::~HelloGL(void) {

}