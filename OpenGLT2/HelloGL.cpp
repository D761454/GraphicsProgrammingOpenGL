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
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = -5.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	camera->angleX = 0.0f; camera->angleY = 0.0f; 
	camera->radius = camera->eye.z - (camera->eye.z + camera->center.z);
	camera->pitch = 0.0f; camera->yaw = -90.0f;

	Vector3 Target;
	Target.x = 0.0f; Target.y = 0.0f; Target.z = 0.0f;

	// if use, must call in update VVV
	camera->direction = Normalize(camera->eye, Target); // just here for principle
	camera->relativeRight = Normalize(CrossProduct(camera->up, camera->direction)); // just here for principle
	camera->relativeUp = CrossProduct(camera->direction, camera->relativeRight); // just here for principle
	// ^^^

	Mesh* cubeMesh = MeshLoader::Load((char*)"Shapes/cube.txt");
	Mesh* skyboxMesh = MeshLoader::Load((char*)"Shapes/skybox.txt");

	Texture2D* texture = new Texture2D();
	texture->Load((char*)"Images/Penguins.raw", 512, 512);

	// edit to make hold trees, trees each will have rand num of obj, all close to one another
	for (int i = 0; i < ObjectAmounts; i++) // initial base amount of obj
	{
		list->MakeNode(&head, new RedCube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f));
	}

	Texture2D* texture2 = new Texture2D();
	texture2->Load((char*)"Images/Skybox.png", 2048, 1536);
	list->MakeNode(&head, new Skybox(skyboxMesh, texture2, camera->eye.x, camera->eye.y, camera->eye.z));

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

	list->DrawList(head);

	// FPS text
	TextPos v = { 10.0f, 770.0f };
	Color c = { 0.0f, 1.0f, 0.0f };
	char fpsArray[20];

	//frames++;
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = currentTime - lastTime; // ms
	lastTime = currentTime;

	fps = round(1000 / deltaTime);
	deltaTime /= 1000; // s

	/*if (currentTime - lastTime > 1000) { // makes less flashy / speedy fps display
		fps = frames * 1000 / (currentTime - lastTime);
		deltaTime = 1 / fps;
		cout << deltaTime << endl;
		lastTime = currentTime;
		frames = 0;
	}*/

	sprintf_s(fpsArray, "FPS:%.0f", fps); // converts float to char
	DrawString(fpsArray, &v, &c);

	glFlush(); // flush scene to graphics card
	glutSwapBuffers();
}

void HelloGL::Keyboard(unsigned char key, int x, int y) {
	float speed = 10.0f * deltaTime;
	if (key == 'q') {
		glutExit();
	}
	if (key == 'd') { // normalized to not be different based on cam center
		camera->eye = Add(camera->eye, Multiply(Normalize(CrossProduct(camera->center, camera->up)), speed));
	}
	if (key == 'a') {
		camera->eye = Subtract(camera->eye, Multiply(Normalize(CrossProduct(camera->center, camera->up)), speed));
	}
	if (key == 'w') { 
		camera->eye = Add(camera->eye, Multiply(camera->center, speed));
	}
	if (key == 's') {
		camera->eye = Subtract(camera->eye, Multiply(camera->center, speed));
	}
	if (key == 32) { // space bar
		Mesh* cubeMesh = MeshLoader::Load((char*)"Shapes/cube.txt");

		Texture2D* texture = new Texture2D();
		texture->Load((char*)"Images/Penguins.raw", 512, 512);

		list->MakeNode(&head, new RedCube(cubeMesh, texture, camera->eye.x + camera->center.x * 50, camera->eye.y + camera->center.y * 50, camera->eye.z + camera->center.z * 50));

	}
	if (key == 8) { // backspace
		list->DeleteSelected(&head, camera);
	}
}

void HelloGL::Mouse(int button, int state, int x, int y) {
	if (button == 0 && state == 0) { // LMB
		list->SelectNode(&head, camera);
	}
	if (button == 2 && state == 0) { // RMB
		RMB = true;
	}
	if (button == 2 && state == 1) {
		RMB = false;
	}
	curX = x;
	curY = y;
}

void HelloGL::Motion(int x, int y) {
	// change cam center
	// Euler Angles - pitch, yaw, roll
	// pitch - up/down
	// yaw - l/r
	// roll - not needed for this as not making a plane simulation
	// can use these to make new direction to look at
	// if length = 1, cos x/1 and sin y/1
	// radians tie angle and length - nice
	if (RMB) {
		offsetX = x - curX;
		offsetY = curY - y;

		const float sensitivity = 0.1f;

		// reduce strength to slow movement
		offsetX *= sensitivity;
		offsetY *= sensitivity;

		camera->yaw += offsetX;
		camera->pitch += offsetY;

		// prevents camera flipping - had when using keyboard for cam rotation
		if (camera->pitch > 89.0f)
			camera->pitch = 89.0f;
		if (camera->pitch < -89.0f)
			camera->pitch = -89.0f;

		camera->center = Normalize(CamLook(camera));

		if (x != curX || y != curY) {
			glutWarpPointer(curX, curY);
		}
	}
}

Vector3 HelloGL::CamLook(Camera* camera) {
	// x relates to cos yaw
	// z relates to sin yaw
	// y relates to sin pitch, x and z relate to cos pitch too
	Vector3 temp;
	temp.x = cos(camera->yaw * (M_PI / 180)) * cos(camera->pitch * (M_PI / 180));
	temp.z = sin(camera->yaw * (M_PI / 180)) * cos(camera->pitch * (M_PI / 180));

	temp.y = sin(camera->pitch * (M_PI / 180));
	return temp;
}

Vector3 HelloGL::Normalize(Vector3 one, Vector3 two) {
	float nx = one.x - two.x;
	float ny = one.y - two.y;
	float nz = one.z - two.z;
	float length = sqrt((nx*nx)+(ny*ny)+(nz*nz));
	Vector3 Normalized;
	Normalized.x = nx / length;
	Normalized.y = ny / length;
	Normalized.z = nz / length;
	return Normalized;
}

Vector3 HelloGL::Normalize(Vector3 one) {
	float length = sqrt((one.x * one.x) + (one.y * one.y) + (one.z * one.z));
	Vector3 Normalized;
	Normalized.x = one.x / length;
	Normalized.y = one.y / length;
	Normalized.z = one.z / length;
	return Normalized;
}

Vector3 HelloGL::CrossProduct(Vector3 one, Vector3 two) {
	// return vector perpendicular to one and two
	// can be used for relative vectors when player rotates view around diff axis (up and right like in tutorials)
	Vector3 crossProduct;
	crossProduct.x = ((one.y * two.z) - (one.z * two.y));
	crossProduct.y = ((one.z * two.x) - (one.x * two.z));
	crossProduct.z = ((one.x * two.y) - (one.y * two.x));

	return crossProduct;
}

Vector3 HelloGL::Multiply(Vector3 vector, float scalar) {
	Vector3 temp;
	temp.x = vector.x * scalar;
	temp.y = vector.y * scalar;
	temp.z = vector.z * scalar;
	return temp;
}

Vector3 HelloGL::Add(Vector3 one, Vector3 two) {
	Vector3 temp;
	temp.x = one.x + two.x;
	temp.y = one.y + two.y;
	temp.z = one.z + two.z;
	return temp;
}

Vector3 HelloGL::Subtract(Vector3 one, Vector3 two) {
	Vector3 temp;
	temp.x = one.x - two.x;
	temp.y = one.y - two.y;
	temp.z = one.z - two.z;
	return temp;
}

void HelloGL::Update() {
	glLoadIdentity(); // reset Modelview Matrix
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, 
		camera->eye.x + camera->center.x, camera->eye.y + camera->center.y, camera->eye.z + camera->center.z, 
		camera->up.z, camera->up.y, camera->up.z);

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	list->UpdateList(head);

	glutPostRedisplay();
}

HelloGL::~HelloGL(void) {
	delete camera;
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