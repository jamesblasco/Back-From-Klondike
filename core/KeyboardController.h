#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "GLCore.h"
#include "../utils/Utils.h"


static class Keyboard {
	static enum Arrows {
		NONE,
		LEFT = GLUT_KEY_LEFT,
		RIGHT = GLUT_KEY_RIGHT,
		UP = GLUT_KEY_UP,
		DOWN = GLUT_KEY_DOWN,
	} arrows;
public:
	static void onArrowDown(int key, int x, int y);
	static void onKeyDown(unsigned char key, int x, int y);
} keyboard;


#endif