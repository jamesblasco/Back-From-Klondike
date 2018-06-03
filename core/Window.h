//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef WINDOW_H
#define WINDOW_H

#include "GLCore.h"
#include "../utils/Utils.h"
#include <math.h>


//
// WINDOW
//
// Control window screen size and relationship between the proportion of screen coordinates and the opengl coordinates
// Initially created to allow the use of buttons within the window but not used in entirety
//
static class Window {
	GLint viewport[4]; // Hold the viewport info
	GLdouble modelview[16]; // Hld the modelview info
	GLdouble projection[16]; // Hold the projection matrix info
	GLfloat winX, winY, winZ; // Hold screen x,y,z coordinates
	GLdouble worldX, worldY, worldZ; // Hold opengl x,y,z coordinates
public:
	static int width;
	static int height;

	// Init window params with default size values
	Window(int width = 0, int height = 0) {
		this->width = width;
		this->height = height;
	}

	// Changes windows size
	void updateSize() {
		this->width = glutGet(GLUT_WINDOW_WIDTH);
		this->height = glutGet(GLUT_WINDOW_HEIGHT);
	}

	static void onResize(int w, int h); // Callback for opengl function glutReshapeFunc


	//Not used
	void setCursor(int x, int y) {
		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;
		glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

		//get the world coordinates from the screen coordinates
	}
	//Not used
	Position getCursor() { return Position((float)worldX, (float)worldY, (float)worldZ); }
	
	
} window;
#endif