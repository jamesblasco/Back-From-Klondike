//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#include "Lines.h"

void Lines::draw() {

	/*std::cout << "draw";
	glTranslatef(0, 0, -5);

	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(2.5, 0.0, 0.0);
	glVertex3f(-2.5, 0.0, 0);
	glEnd();
	*/
}


void Lines::updateStatus(Window* window) {
	Position2D cursor = window->getCursor();
	//std::cout << "MOUSE x:" << cursor.x << " y:" << cursor.y <<  " height:" << window->height << " width:"<< window->width <<"\n";
	this->pos = Position(cursor.x/1000, cursor.y/1000);
}

