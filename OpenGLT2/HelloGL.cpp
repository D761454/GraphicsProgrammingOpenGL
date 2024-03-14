#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(Display); // call back function
	glutMainLoop();
}

HelloGL::~HelloGL(void) {

}