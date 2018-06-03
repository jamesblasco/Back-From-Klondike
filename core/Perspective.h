//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "GLCore.h"
#include "../utils/Utils.h"


//
// Perspective
//
// Control the perspective of the game
//
static class Perspective {
 public:
	static float zoom; 
	static Position pos; // Distance from observer (X, Y, Z)
	static Position rot; // Rotation from observer (X, Y, Z)

	// Move distance from observer
	static void move(Position variation) {
		pos.x += (float) 0.5f * (variation.x * cos(rot.y*PI / 180) - variation.y * sin(rot.y*PI / 180));
		pos.z += (float) 0.5f * (variation.y * cos(rot.y*PI / 180) + variation.x * sin(rot.y*PI / 180));
	}
	// Change rotation from observer
	static void rotate(Position variation) {
		rot.y += (float) 0.5f * variation.x;
		rot.x += (float) 0.5f * variation.y;
		//rot.z += (float) 0.5f * variation.y * sin(rot.y*PI / 180);
	}
	// set Perspective in game with openGl
	static void draw() {
		//gluLookAt(pos.x, pos.y, pos.z -zoom, 0.1, 0.1, 0.1, 0, 1, 1);
		glTranslatef(0, 0, -zoom);

		glRotatef(rot.x, 1, 0, 0); // Rotate X-Axis
	    glRotatef(rot.z, 0, 0, 1); // Rotate Z-Axis
		glRotatef(rot.y, 0, 1, 0); // Rotate Y-Axis

		glTranslatef(0, 0, pos.z); 
		glTranslatef(0, pos.y, 0);
		glTranslatef(pos.x, 0, 0);

	}
} perspective;


#endif