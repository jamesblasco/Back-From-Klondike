#ifndef MOUSE_H
#define MOUSE_H

#include "GLCore.h"
#include "../utils/Utils.h"


static class Mouse {
public:
	static enum Buttons {
		NONE,
		LEFT = GLUT_LEFT_BUTTON,
		CENTER = GLUT_MIDDLE_BUTTON,
		RIGHT = GLUT_RIGHT_BUTTON,
	} button;
	static Position2D pos;

	Mouse();
	
	static Position2D update(int x, int y);	
	static void onMotion(int x, int y);
	static void onClickMotion(int x, int y);
	static void onClick(int button, int state, int x, int y);

	Position worldPosition(Position *start);
} mouse;




#endif
