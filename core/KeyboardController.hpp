//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "GLCore.hpp"
#include "../utils/Utils.hpp"

//
// Keyboard
//
// Control when a key on the keyboard is pressed
//
static class Keyboard {
	//Not used in production
	static enum Arrows {
		NONE,
		LEFT = GLUT_KEY_LEFT, // LEFT ARROW
		RIGHT = GLUT_KEY_RIGHT, // RIGTH ARROW
		UP = GLUT_KEY_UP, // UP ARROW
		DOWN = GLUT_KEY_DOWN, // DOWN ARROW
	} arrows;
public:
	static void onArrowDown(int key, int x, int y); //When an arrow key is pressed
	static void onKeyDown(unsigned char key, int x, int y); //When an normal key is pressed
} keyboard;


#endif