#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	rotation = 0.0f;
	
	struct point3D {
		float x;
		float y;
		float z;
	};

	struct colour {
		float r;
		float g;
		float b;
		float a;
	};

	struct polygon {
		int a;
		int b;
		int c;
	};

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE); // enable double buffering - reduce flicker
	//glutInitWindowSize(16*50, 9*50);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");

	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMouseFunc(GLUTCallbacks::Mouse);
	glutMotionFunc(GLUTCallbacks::Motion);
	glutDisplayFunc(GLUTCallbacks::Display); // call back function
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glutMainLoop();
}

void HelloGL::Display() {
	// drawing code
	glClear(GL_COLOR_BUFFER_BIT); // clear scene

	DrawTriangleAll();

	glFlush(); // flush scene to graphics card
	glutSwapBuffers();
}

void HelloGL::Keyboard(unsigned char key, int x, int y) {
	if (key == 'd') {
		rotation += 0.5f;
	}
	if (key == 'a') { // flip rotation 
		rotation -= 0.5f;
	}
}

void HelloGL::Mouse(int button, int state, int x, int y) {

}

void HelloGL::Motion(int x, int y) {

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

void HelloGL::DrawTriangleAll() {
	glPushMatrix();
	glTranslatef(-0.66, 0.25, 0); // obj centre (centre of the 1/6 chunk of window)
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glTranslatef(0.66, -0.25, 0); // origin pos
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
	glTranslatef(0, 0.325, 0);
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glTranslatef(0, -0.325, 0);
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
	glTranslatef(0.66, 0.325, 0);
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glTranslatef(-0.66, -0.325, 0);
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
	glTranslatef(-0.66, -0.5, 0);
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glTranslatef(0.66, 0.5, 0);
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
	glTranslatef(0, -0.5, 0);
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glTranslatef(0, 0.5, 0);
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
	glTranslatef(0.66, -0.5, 0);
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glTranslatef(-0.66, 0.5, 0); 
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
	if (rotation >= 360.0f || rotation <= -360.0f) {
		rotation = 0.0f;
	}

	glutPostRedisplay();
}

HelloGL::~HelloGL(void) {

}