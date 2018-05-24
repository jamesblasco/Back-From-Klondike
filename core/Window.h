#ifndef WINDOW_H
#define WINDOW_H

#include "GLCore.h"
#include "../utils/Utils.h"
#include <math.h>

static class Window {
	GLint viewport[4]; //var to hold the viewport info
	GLdouble modelview[16]; //var to hold the modelview info
	GLdouble projection[16]; //var to hold the projection matrix info
	GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
	GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates
public:
	static int width;
	static int height;

	Window(int width = 0, int height = 0) {
		this->width = width;
		this->height = height;
	}
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
	Position getCursor() { return Position((float)worldX, (float)worldY, (float)worldZ); }
	void updateSize() {
		this->width = glutGet(GLUT_WINDOW_WIDTH);
		this->height = glutGet(GLUT_WINDOW_HEIGHT);
	}
	
	static void onResize(int w, int h);
} window;
#endif