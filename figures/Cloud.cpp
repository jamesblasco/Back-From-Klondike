//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#include "Cloud.h"

void Cloud::draw() {

	glPushMatrix();

	glScalef(7, 7, 1);
	glTranslatef(0, 12, -500);

	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.5, 0.5, 0.5);

	glVertex3f(10.0, 7, -50.0);
	glVertex3f(15, 10.0, -50.0);
	glVertex3f(7, 15, -50.0);
	glVertex3f(0.0, 20.0, -50.0);
	glVertex3f(-7, 15, -50.0);
	glVertex3f(-14, 16, -50.0);
	glVertex3f(-17, 10.0, -50.0);
	glVertex3f(-15, 7, -50.0);
	glVertex3f(-10.0, 5, -50.0);

	glEnd();
	glPopMatrix();
}
