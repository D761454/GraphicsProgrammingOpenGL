#include "GLUTCallbacks.h"
#include "HelloGL.h"

namespace GLUTCallbacks {
	namespace { // anonymous namespace
		// initialise to a null pointer
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl) {
		helloGL = gl;
	}

	void Timer(int preferredRefresh) {
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	void Keyboard(unsigned char key, int x, int y) {
		helloGL->Keyboard(key, x, y);
	}

	void Mouse(int button, int state, int x, int y) {
		helloGL->Mouse(button, state, x, y);
	}

	void Motion(int x, int y) {
		helloGL->Motion(x, y);
	}

	void Display() {
		if (helloGL != nullptr) {
			helloGL -> Display();
		}
	}

	void ObjectMenu(int value) {
		helloGL->ObjectMenu(value);
	}

	void SpawnMenu(int value) {
		helloGL->SpawnMenu(value);
	}

	void ColorMenu(int value) {
		helloGL->ColorMenu(value);
	}
}