//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#include "Cloud.h"

//Draw random cloud
void Cloud::draw() {
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glRotatef(relative * 360, 0, 1, 0);
	
	glPushMatrix();
		
		rotate(Y, 0.00008 * (relative*10 + 1));
		glTranslatef(relative * 100, relative * 400, relative * 100);
		glTranslatef(0, -3200, -12000);
	

		glColor4f(1, 1, 1, 1);
	
		glutSolidSphere(1000 - 10* relative, 20, 20);
	
		glTranslatef(100 - 10 * relative, 100, 100);
		glutSolidSphere(800 - 10 * relative, 20, 20);
	
		glTranslatef(1000 - 10 * relative, 100, -200);
		glutSolidSphere(1100 - 10 * relative, 20, 20);

	glPopMatrix();

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
}
