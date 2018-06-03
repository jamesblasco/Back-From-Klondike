//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef MOUSE_H
#define MOUSE_H

#include "GLCore.h"
#include "../utils/Utils.h"

//
// Keyboard
//
// Control when a button on the mouse is pressed
//
static class Mouse {
public:
	static enum Buttons {
		NONE,
		LEFT = GLUT_LEFT_BUTTON,
		CENTER = GLUT_MIDDLE_BUTTON,
		RIGHT = GLUT_RIGHT_BUTTON,
	} button;
	static Position2D pos; // 2D VECTOR for mouse position in the screen

	Mouse(); //Init mouse controller
	
	static Position2D update(int x, int y);	 // update mouse position in the screen
	static void onMotion(int x, int y); // Callback for openGL glutPassiveMotionFunc - when mouse pos on the screen changes
	static void onClickMotion(int x, int y); // Callback for openGL glutMotionFunc  - when mouse pos on the screen changes when clicked
	static void onClick(int button, int state, int x, int y); // Callback for openGL glutMouseFunc  - when mouse is clicked

	Position worldPosition(Position *start); // Not used function. Converts mouse position into opengl 3D vector
} mouse;




#endif
