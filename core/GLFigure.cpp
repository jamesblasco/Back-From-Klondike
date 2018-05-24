
#include "GLFigure.h"
#include <string.h>
#include <iostream>


using namespace std;

Figure::Figure() {
	this->pos = Position(0,0,0);
	this->rot= Position(0, 0, 0);
}

Figure::Figure(float x, float y, float z) {
	this->pos = Position(x, y, z);
	this->rot = Position(0, 0, 0);
}

void calculateRotation(float * axis, float speed, float val) {
	*axis += speed;
	if (val != -1 && *axis > val) *axis = val;
	else if (*axis>360) *axis = 0;
}

void Figure::move(float x, float y, float z, float speed){
	calculateRotation(&pos.x, speed, x);
	calculateRotation(&pos.y, speed, y);
	calculateRotation(&pos.z, speed, z);
	glTranslatef(pos.x, pos.y, pos.z);
}

void Figure::rotate (Axis axis, float speed, float angle){
	switch (axis) {
		case X: {	
			calculateRotation(&rot.x, speed, angle);
			glRotatef(rot.x, 1, 0, 0);
			break;
		}
		case Y: {
			calculateRotation(&rot.y, speed, angle);
			glRotatef(rot.y, 0, 1, 0);
			break;
		}
		case Z: {
			calculateRotation(&rot.z,speed, angle);
			glRotatef(rot.z, 0, 0, 1);
			break;
		}
	}
}

void Figure::jump(float distance, float speed) {
	static float s = 0;
	s += 0.005*speed;
	
	pos.y = distance*sin(s);
	if (s>3.14) { s = 0; }
	glTranslatef(0, pos.y, 0);
	
}


void Figure::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	draw();
	glPopMatrix();
}

