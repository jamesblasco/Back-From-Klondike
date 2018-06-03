//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#include "Button.h"
#include "../core/MouseController.h"

void Button::draw() {
	glTranslatef(0, 0, -5);

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0.05, 0.0);
	glVertex3f(0.05, 0.05, 0.0);
	glVertex3f(0.05, -0.05, 0.0);
	glVertex3f(-0.05, -0.05, 0.0);
	glEnd();
	
}


void Button::updateStatus(Window* window) {
	Position start = Position(0, 0, 0);
	Position cursor = mouse.pos;
	//std::cout << "MOUSE x:" << cursor.x << " y:" << cursor.y << " z:" << cursor.z <<"\n";
	this->pos = Position(cursor.x-Window::width/2, cursor.y - Window::height / 2, 0 );
}

