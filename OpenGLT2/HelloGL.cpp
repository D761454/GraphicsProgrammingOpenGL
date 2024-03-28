#include "HelloGL.h"

Vertex HelloGL::indexedVertices[] = { // incompatible with TexCoords, need to separate vertices, modelling tools will do this for me
	1,1,1,		-1,1,1,
	-1,-1,1,	1,-1,1,
	1,-1,-1,	1,1,-1,
	-1,1,-1,	-1,-1,-1
};

Color HelloGL::indexedColors[] = {
	1,1,1,1,	1,1,0,1,
	1,0,0,1,	1,0,1,1,
	0,0,1,1,	0,1,1,1,
	0,1,0,1,	0,0,0,1
};

GLushort HelloGL::indices[] = {
	0,1,2,	2,3,0, // front
	0,3,4,	4,5,0, // right
	0,5,6,	6,1,0, // top
	1,6,7,	7,2,1, // left
	7,4,3,	3,2,7, // bottom
	4,7,6,	6,5,4 // back
};

HelloGL::HelloGL(int argc, char* argv[]) {
	rotationx = 0.0f;
	rotationy = 0.0f;

	// camera setup
	camera = new Camera();
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	// glut setup
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // enable double buffering - reduce flicker, | GLUT_DEPTH enable depth testing
	//glutInitWindowSize(16*50, 9*50);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");

	glEnable(GL_CULL_FACE); // leave off for now until figure out how to do normal stuff
	glCullFace(GL_BACK);
	//glEnable(GL_DEPTH_TEST);

	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMouseFunc(GLUTCallbacks::Mouse);
	glutMotionFunc(GLUTCallbacks::Motion);
	glutDisplayFunc(GLUTCallbacks::Display); // call back function
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // identity matricy - 1 down diag, 0 all else e.g. 1: [1, 0, 0] 2: [0, 1, 0] 3: [0, 0, 1] (n*n size)
	glViewport(0, 0, 800, 800); // set viewport to be window
	gluPerspective(45, 1, 0, 1000); // set correct perspective: FOV, ASPECT RATIO, NEAR CLIPPING DIST, FAR CLIPPING DIST
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

void HelloGL::Display() {
	// drawing code
	glClear(GL_COLOR_BUFFER_BIT); // clear scene // | GL_DEPTH_BUFFER_BIT

	 DrawIndexedCube();

	glFlush(); // flush scene to graphics card
	glutSwapBuffers();
}

void HelloGL::Keyboard(unsigned char key, int x, int y) {
	if (key == 'd') {
		// camera->up.z += 0.1f; // diag z
		camera->eye.x -= 0.1f; // horizontal
	}
	if (key == 'a') {
		// camera->up.z -= 0.1f; // diag z
		camera->eye.x += 0.1f; // horizontal
	}
	if (key == 'w') { 
		// camera->eye.z -= 0.1f; // zoom
		camera->eye.y += 0.1f; // vertical
	}
	if (key == 's') {
		// camera->eye.z+= 0.1f; // zoom
		camera->eye.y -= 0.1f; // vertical
	}
	if (key == '1') {
		camera->eye.z -= 0.1f; // zoom
	}
	if (key == '2') {
		camera->eye.z += 0.1f; // zoom
	}
}

void HelloGL::Mouse(int button, int state, int x, int y) {

}

void HelloGL::Motion(int x, int y) {

}

void HelloGL::DrawIndexedCube() {
	glPushMatrix();
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < sizeof(indices)/2; i++) {
			glColor4fv(&indexedColors[indices[i]].r); // v on end to use &
			glVertex3fv(&indexedVertices[indices[i]].x);
		}
		glEnd(); // end drawing
	glPopMatrix();
}

void HelloGL::DrawTriangleAll() {
	glPushMatrix();
	glTranslatef(-0.66, 0.25, 0); // obj centre (centre of the 1/6 chunk of window)
	glRotatef(rotationx, 0.0f, 0.0f, -1.0f);
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
	glRotatef(rotationx, 0.0f, 0.0f, -1.0f);
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
	glRotatef(rotationx, 0.0f, 0.0f, -1.0f);
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
	glRotatef(rotationx, 0.0f, 0.0f, -1.0f);
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
	glRotatef(rotationx, 0.0f, 0.0f, -1.0f);
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
	glRotatef(rotationx, 0.0f, 0.0f, -1.0f);
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

bool HelloGL::LoadObj(char* path) {
	char* tempObjData; int fileSize; ifstream inFile;
	inFile.open(path, ios::binary);

	if (!inFile.good()) {
		cerr << "Can't open object file: " << path << endl;
		return false;
	}

	inFile.seekg(0, ios::end); // seek to end of file
	fileSize = (int)inFile.tellg(); // get current pos in file - End = total filesize
	tempObjData = new char[fileSize]; // create new array to store data
	inFile.seekg(0, ios::beg); // seek back to beginning of file
	inFile.read(tempObjData, fileSize); // read in all data at once
	inFile.close();

	/* 
	search through array, v - vertex list, f - index list
	*/


	cout << path << " Loaded." << endl;


	delete[] tempObjData; // clear up unneeded data
	return true;
}

void HelloGL::Update() {
	glLoadIdentity(); // reset Modelview Matrix
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.z, camera->up.y, camera->up.z);

	if (rotationx >= 360.0f || rotationx <= -360.0f) {
		rotationx = 0.0f;
	}
	if (rotationy >= 360.0f || rotationy <= -360.0f) {
		rotationy = 0.0f;
	}

	glutPostRedisplay();
}

HelloGL::~HelloGL(void) {
	delete camera;
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