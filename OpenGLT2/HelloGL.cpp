#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(Display);
	glutMainLoop();
}