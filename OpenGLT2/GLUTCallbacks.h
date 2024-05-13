#pragma once
class HelloGL;

namespace GLUTCallbacks {
	void Init(HelloGL* gl);

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);

	void Mouse(int button, int state, int x, int y);

	void Motion(int x, int y);

	void Display();

	void ObjectMenu(int value);

	void SpawnMenu(int value);
}