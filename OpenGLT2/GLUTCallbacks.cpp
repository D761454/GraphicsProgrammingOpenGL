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

	void Display() {
		if (helloGL != nullptr) {
			helloGL -> Display();
		}
	}
}