
#include "GLFigure.h"
#include "GLUtils.h"

Snowman::Snowman() {};

void Snowman :: draw(){

	
	glPushMatrix();

	move(0, 3, 0, 0.01);
	jump(0.4, 1);
	rotate(X, 0.6, 90);
	rotate(Y, 0.2);
	rotate(Z, 0, 0);
		
	// Draw Body	
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(0.15f, 20, 20);


	// Draw Heads
	glTranslatef(0.0f, 0.15f + 0.08f, 0.0f);
	glutSolidSphere(0.08f, 20, 20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.015f, 0.06f, 0.08f);
	glutSolidSphere(0.015f, 10, 10);
	glTranslatef(-0.03f, 0.0f, 0.0f);
	glutSolidSphere(0.015f, 10, 10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
	glutSolidCone(0.03f, 0.15f, 10, 2);
	glPopMatrix();

	
};