#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display); // call back function
	glutMainLoop();
}

void HelloGL::Display() {
	// drawing code
	glClear(GL_COLOR_BUFFER_BIT); // clear scene
	glBegin(GL_POLYGON); // begin drawing
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glVertex2f(-0.75, 0.5); // top left
		glVertex2f(0.75, 0.5); // top right
		glVertex2f(0.75, -0.5); // bottom right
		glVertex2f(-0.75, -0.5); // bottom left
	glEnd(); // end drawing
	glFlush(); // flush scene to graphics card
}

HelloGL::~HelloGL(void) {

}