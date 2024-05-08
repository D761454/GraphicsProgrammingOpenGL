#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	InitGL(argc, argv); // 1st
	InitObjects();
	InitLighting();
	glutMainLoop();
}

void HelloGL::InitObjects() {
	// camera setup
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 50.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	camera->angleX = 0.0f; camera->angleY = 0.0f; camera->radius = camera->eye.z - camera->center.z;

	Mesh* cubeMesh = MeshLoader::Load((char*)"Shapes/cube.txt");

	Texture2D* texture = new Texture2D();
	texture->Load((char*)"Images/Penguins.raw", 512, 512);

	for (int i = 0; i < ObjectAmounts; i++) // initial base amount of obj
	{
		//objects[i] = new RedCube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
		list->MakeNode(&head, new RedCube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f));
	}

	lastTime = 0;
}

void HelloGL::InitGL(int argc, char* argv[]) {
	// glut setup
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // enable double buffering - reduce flicker, | GLUT_DEPTH enable depth testing
	//glutInitWindowSize(16*50, 9*50);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Yoinky Sploinky");

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

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
}

void HelloGL::InitLighting() {
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->ambient.x = 0.2;
	_lightData->ambient.y = 0.2;
	_lightData->ambient.z = 0.2;
	_lightData->ambient.w = 1.0;
	_lightData->diffuse.x = 0.8;
	_lightData->diffuse.y = 0.8;
	_lightData->diffuse.z = 0.8;
	_lightData->diffuse.w = 1.0;
	_lightData->specular.x = 0.2;
	_lightData->specular.y = 0.2;
	_lightData->specular.z = 0.2;
	_lightData->specular.w = 1.0;
}

void HelloGL::DrawString(const char* text, TextPos* position, Color* color) {
	glDisable(GL_TEXTURE_2D); // without this, text appears darker
	glDisable(GL_LIGHTING); // needed as without, text = lighting colour
	glEnableClientState(GL_COLOR); // enable colour

	glMatrixMode(GL_PROJECTION); // needed for ortho
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 800); // 2 view of window , means i can place text based on window

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glRasterPos2i(position->x, position->y); // x and y raster position, window coordinates

	glColor3fv(&color->r);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glDisableClientState(GL_COLOR);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
}

void HelloGL::Display() {
	// drawing code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear scene 

	/*for (int i = 0; i < ObjectAmounts; i++)
	{
		objects[i]->Draw();
	}*/

	list->DrawList(head);


	// FPS text
	TextPos v = { 10.0f, 770.0f };
	Color c = { 0.0f, 1.0f, 0.0f };
	char fpsArray[20];

	frames++;
	currentTime = glutGet(GLUT_ELAPSED_TIME);

	if (currentTime - lastTime > 1000) {
		fps = frames * 1000 / (currentTime - lastTime);
		lastTime = currentTime;
		frames = 0;
	}

	sprintf_s(fpsArray, "FPS:%.2f", fps); // converts float to char
	DrawString(fpsArray, &v, &c);

	glFlush(); // flush scene to graphics card
	glutSwapBuffers();
}

void HelloGL::Keyboard(unsigned char key, int x, int y) {
	if (key == 'd') {
		camera->center.x += 0.1f;
		camera->eye.x += 0.1f;
	}
	if (key == 'a') {
		camera->center.x -= 0.1f;
		camera->eye.x -= 0.1f;
	}
	if (key == 'w') { 
		camera->center.z -= 0.1f;
		camera->eye.z -= 0.1f;
	}
	if (key == 's') {
		camera->center.z += 0.1f;
		camera->eye.z += 0.1f;
	}
	if (key == '9') {
		camera->center.y += 0.1f;
		camera->eye.y += 0.1f;
	}
	if (key == '0') {
		camera->center.y -= 0.1f;
		camera->eye.y -= 0.1f;
	}
	// rotate around origin
	if (key == '4') {
		camera->angleX += 0.1f;
		if (camera->angleX > 6.3f) {
			camera->angleX = 0.0f;
		}
		camera->eye.x = sin(camera->angleX) * camera->radius;
		camera->eye.z = cos(camera->angleX) * camera->radius;
	}
	if (key == '6') {
		camera->angleX -= 0.1f;
		if (camera->angleX < -6.3) {
			camera->angleX = 0.0f;
		}
		camera->eye.x = sin(camera->angleX) * camera->radius;
		camera->eye.z = cos(camera->angleX) * camera->radius;
	}
	if (key == '8') {
		if (camera->angleY < 1.5f) {
			camera->angleY += 0.1f;
		}
		camera->eye.y = sin(camera->angleY) * camera->radius;
		camera->eye.z = cos(camera->angleY) * camera->radius;
	}
	if (key == '2') {
		if (camera->angleY > -1.5f) {
			camera->angleY -= 0.1f;
		}
		camera->eye.y = sin(camera->angleY) * camera->radius;
		camera->eye.z = cos(camera->angleY) * camera->radius;
	}
}

void HelloGL::Mouse(int button, int state, int x, int y) {
	if (button == 0 && state == 1) {
		Mesh* cubeMesh = MeshLoader::Load((char*)"Shapes/cube.txt");

		Texture2D* texture = new Texture2D();
		texture->Load((char*)"Images/Penguins.raw", 512, 512);

		list->MakeNode(&head, new RedCube(cubeMesh, texture, camera->center.x, camera->center.y, camera->center.z));
	}
	if (button == 2 && state == 1) {

		list->DeleteAtPos(&head, camera);
	}
}

void HelloGL::Motion(int x, int y) {

}


void HelloGL::Update() {
	glLoadIdentity(); // reset Modelview Matrix
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.z, camera->up.y, camera->up.z);

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	/*for (int i = 0; i < ObjectAmounts; i++)
	{
		objects[i]->Update();
	}*/
	list->UpdateList(head);

	glutPostRedisplay();
}

HelloGL::~HelloGL(void) {
	delete camera;
	delete[] objects;
	list->DeleteList(&head);
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