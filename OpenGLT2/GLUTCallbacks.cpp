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

	void Display() {
		if (helloGL != nullptr) {
			helloGL -> Display();
		}
	}
}