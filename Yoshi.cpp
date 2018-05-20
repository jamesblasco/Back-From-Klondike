#include "Game.h"
#include "FrameTimer.h"

void Yoshi :: init () {
	Load("tris.md2");
	// write memory usage
	std::cout << "memory usage " << (GetDataSize() / 1024.0f) << "kb\n";
	texture = loadPcxTexture("yoshi.pcx");
}

void Yoshi::draw() {
	
	glPushMatrix();

		jump(20, 1);

		rotate(Y, 0.01);

		glTranslatef(0, 20, 0);

		glEnable(GL_TEXTURE_2D);
		glColor3f(1.0f, 1.0f, 1.0f);
		
		glBindTexture(GL_TEXTURE_2D, texture);
		Render();

		glDisable(GL_TEXTURE_2D);

	glPopMatrix();
		
}

void Yoshi::update() {
	Update(FrameTime());
}