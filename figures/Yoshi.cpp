
#include "Yoshi.h"
#include "../FrameTimer.h"

void Yoshi :: init () {
	Load("tris.md2");
	// write memory usage
	std::cout << "memory usage " << (GetDataSize() / 1024.0f) << "kb\n";
	loadPcxTexture("yoshi.pcx");
}

void Yoshi::draw() {
	
	glPushMatrix();

		jump(7, 2);

		rotate(Y, 1, -45);
		rotate(Y, 2);


		glTranslatef(0, 23, 0);

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