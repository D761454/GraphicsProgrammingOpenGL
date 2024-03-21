#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	rotationx = 0.0f;
	rotationy = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // enable double buffering - reduce flicker, | GLUT_DEPTH enable depth testing
	//glutInitWindowSize(16*50, 9*50);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");

	/*glEnable(GL_CULL_FACE); // leave off for now until figure out how to do normal stuff
	glCullFace(GL_BACK);*/
	glEnable(GL_DEPTH_TEST);

	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMouseFunc(GLUTCallbacks::Mouse);
	glutMotionFunc(GLUTCallbacks::Motion);
	glutDisplayFunc(GLUTCallbacks::Display); // call back function
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glutMainLoop();
}

void HelloGL::Display() {
	// drawing code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear scene // | GL_DEPTH_BUFFER_BIT

	DrawCube();

	glFlush(); // flush scene to graphics card
	glutSwapBuffers();
}

void HelloGL::Keyboard(unsigned char key, int x, int y) {
	if (key == 'd') {
		rotationx += 0.5f;
	}
	if (key == 'a') { // flip rotation 
		rotationx -= 0.5f;
	}
	if (key == 'w') {
		rotationy += 0.5f;
	}
	if (key == 's') { // flip rotation 
		rotationy -= 0.5f;
	}
}

void HelloGL::Mouse(int button, int state, int x, int y) {

}

void HelloGL::Motion(int x, int y) {

}

void HelloGL::DrawPolygon(int a, int b, int c, int d) {
	glPushMatrix();
	glRotatef(rotationx, rotationx, rotationy, -1.0f);
	glBegin(GL_QUADS); // begin drawing
	{
		glVertex3fv(&vertices[a].x);
		glVertex3fv(&vertices[b].x);
		glVertex3fv(&vertices[c].x);
		glVertex3fv(&vertices[d].x);
		glEnd(); // end drawing
	}
	glPopMatrix();
}

void HelloGL::DrawCube() {
	for (int i = 0; i < 6; i++) { // change 1 to NUM_POLY for later
		glColor4f(colours[i].r, colours[i].g, colours[i].b, colours[i].a);
		DrawPolygon(indices[i].a, indices[i].b, indices[i].c, indices[i].d);
	}
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

void HelloGL::DrawHexagon() {
	glPushMatrix();
	glRotatef(rotationx, 0.0f, 0.0f, -1.0f);
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
	glRotatef(rotationx, 0.0f, 0.0f, -1.0f);
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
	if (rotationx >= 360.0f || rotationx <= -360.0f) {
		rotationx = 0.0f;
	}
	if (rotationy >= 360.0f || rotationy <= -360.0f) {
		rotationy = 0.0f;
	}

	glutPostRedisplay();
}

HelloGL::~HelloGL(void) {
	delete[] vertices;
	delete[] colours;
	delete[] indices;
}