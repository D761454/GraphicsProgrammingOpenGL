#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	// camera setup
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 50.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	Cube::Load((char*)"cube.txt");
	Teapot::Load((char*)"teapot.obj");

	for (int i = 0; i < 10; i++)
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	teapot = new Teapot(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);

	// glut setup
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // enable double buffering - reduce flicker, | GLUT_DEPTH enable depth testing
	//glutInitWindowSize(16*50, 9*50);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMouseFunc(GLUTCallbacks::Mouse);
	glutMotionFunc(GLUTCallbacks::Motion);
	glutDisplayFunc(GLUTCallbacks::Display); // call back function
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // identity matricy - 1 down diag, 0 all else e.g. 1: [1, 0, 0] 2: [0, 1, 0] 3: [0, 0, 1] (n*n size)
	glViewport(0, 0, 800, 800); // set viewport to be window
	gluPerspective(45, 1, 1, 1000); // set correct perspective: FOV, ASPECT RATIO, NEAR CLIPPING DIST, FAR CLIPPING DIST
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

void HelloGL::Display() {
	// drawing code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear scene 

	for (int i = 0; i < 10; i++)
	{
		cube[i]->Draw();
	}

	teapot->Draw();

	glFlush(); // flush scene to graphics card
	glutSwapBuffers();
}

void HelloGL::Keyboard(unsigned char key, int x, int y) {
	if (key == 'd') {
		camera->center.x += 0.1f;
	}
	if (key == 'a') {
		camera->center.x -= 0.1f;
	}
	if (key == 'w') { 
		camera->center.y += 0.1f;
	}
	if (key == 's') {
		camera->center.y -= 0.1f;
	}
	if (key == '1') {
		camera->eye.z -= 0.1f;
	}
	if (key == '2') {
		camera->eye.z += 0.1f;
	}
}

void HelloGL::Mouse(int button, int state, int x, int y) {
	
}

void HelloGL::Motion(int x, int y) {

}

void HelloGL::Update() {
	glLoadIdentity(); // reset Modelview Matrix
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.z, camera->up.y, camera->up.z);

	for (int i = 0; i < 10; i++)
	{
		cube[i]->Update();
	}

	teapot->Update();

	glutPostRedisplay();
}

HelloGL::~HelloGL(void) {
	delete camera;
	delete[] cube;
	delete teapot;
}

/*
matrix multiplication
[A, B] [E, F]   [(A*E)+(B*G), (A*F)+(B*H)]
[C, D].[G, H] = [(C*E)+(D*G), (C*F)+(D*H)]

E.G. COL 1 ANSWER = 1st and 2nd in row of 1, * 1st and 2nd in col of 2, added together
rows of Matrix A and col of Matrix B determine matrix size. can only * if A col size = B row size

standard *

2 * [2, 0] = [4, 0]
    [3, 4]   [6, 8]
*/

/*
Teapot obj formatting
v x y z		-	where 1st letter on line = v	-	vertex info
f a b c		-	where 1st letter on line = f	-	indices info
*/