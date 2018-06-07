//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#include "Yoshi.hpp"
#include "../include/FrameTimer.hpp"

void Yoshi :: init () {
	InitFrameTimer();
	Load("textures/tris.md2");
	texture.loadPcxTexture("textures/yoshi.pcx");
}

void Yoshi::draw() {
	jump(7, 2);
	rotate(Y, 1, -90);
	glTranslatef(0, 23, 0);

	glEnable(GL_TEXTURE_2D);
		glColor3f(1.0f, 1.0f, 1.0f);	
		glBindTexture(GL_TEXTURE_2D, texture.get());
		Render();
	glDisable(GL_TEXTURE_2D);	
}

void Yoshi::update() {
	Update(FrameTime());
}

void Yoshi::setAnim(unsigned short anim)
{
	SetAnim(anim);
}


void Yoshi::changeAnim()
{
	unsigned short anim;
	if (GetAnim() == 0) anim = 10;
	else if (GetAnim() == 10) anim = 9;
	else anim = 0;
	SetAnim(anim);
}