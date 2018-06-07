//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#include "Snowman.hpp"


Snowman::Snowman() {};

void Snowman :: draw(){
	
	//move(0, 3, 0, 0.01);
	jump(40, 1);
	
	rotate(Y, 0.2);
	rotate(Z, 0, 0);
		
	// Draw Body	
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0,15, 0);
	glutSolidSphere(15, 20, 20);


	// Draw Heads
	glTranslatef(0.0f, 15.0f + 8.0f, 0.0f);
	glutSolidSphere(8.0f, 20, 20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.15f, 0.6f, 0.8f);
	glutSolidSphere(0.15f, 10, 10);
	glTranslatef(-0.3f, 0.0f, 0.0f);
	glutSolidSphere(0.15f, 10, 10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
	glutSolidCone(0.3f, 1.5f, 10, 2);
};