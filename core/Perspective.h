
#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "GLCore.h"
#include "../utils/Utils.h"

static class Perspective {
 public:
	static float zoom;
	static Position pos; //
	static Position rot;

	static void move(Position variation) {
		pos.x += (float) 0.5f * (variation.x * cos(rot.y*PI / 180) - variation.y * sin(rot.y*PI / 180));
		pos.z += (float) 0.5f * (variation.y * cos(rot.y*PI / 180) + variation.x * sin(rot.y*PI / 180));
	}
	static void rotate(Position variation) {

		rot.y += (float) 0.5f * variation.x;
		rot.x += (float) 0.5f * variation.y;
		//rot.z += (float) 0.5f * variation.y * sin(rot.y*PI / 180);
		std::cout << "rot y:" << rot.y << " rot x:" << rot.x << "  rot z:" << rot.z << "\n";

	}
	static void draw() {

		//gluLookAt(pos.x, pos.y, pos.z -zoom, 0.1, 0.1, 0.1, 0, 1, 1);
		glTranslatef(0, 0, -zoom);

		glRotatef(rot.x, 1, 0, 0);
	    glRotatef(rot.z, 0, 0, 1);
		glRotatef(rot.y, 0, 1, 0);

		glTranslatef(0, 0, pos.z);
		glTranslatef(0, pos.y, 0);
		glTranslatef(pos.x, 0, 0);

	}
} perspective;


#endif