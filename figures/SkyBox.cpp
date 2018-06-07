#include "SkyBox.hpp"

//load textures
void SkyBox::init() { 
	textures[(int)SKY::BACK].loadTexBMP("textures/skybox_back.bmp");
	textures[(int)SKY::FRONT].loadTexBMP("textures/skybox_front.bmp");
	textures[(int)SKY::RIGHT].loadTexBMP("textures/skybox_right.bmp");
	textures[(int)SKY::LEFT].loadTexBMP("textures/skybox_left.bmp");
	textures[(int)SKY::UP].loadTexBMP("textures/skybox_up.bmp");
	textures[(int)SKY::DOWN].loadTexBMP("textures/skybox_down.bmp");
}

void SkyBox::draw() {

	glTranslatef(0, -8000, 0);
	

	glColor(Color::WHITE);
	glEnable(GL_TEXTURE_2D);

		const int D = 20000;
		/* Sides */
		glBindTexture(GL_TEXTURE_2D, textures[(int)SKY::RIGHT].get());
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-D, -D, -D);
			glTexCoord2f(1, 0); glVertex3f(+D, -D, -D);
			glTexCoord2f(1, 1); glVertex3f(+D, +D, -D);
			glTexCoord2f(0, 1); glVertex3f(-D, +D, -D);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textures[(int)SKY::FRONT].get());
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(+D, -D, -D);
			glTexCoord2f(1, 0); glVertex3f(+D, -D, +D);
			glTexCoord2f(1, 1); glVertex3f(+D, +D, +D);
			glTexCoord2f(0, 1); glVertex3f(+D, +D, -D);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textures[(int)SKY::LEFT].get());
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(+D, -D, +D);
			glTexCoord2f(1, 0); glVertex3f(-D, -D, +D);
			glTexCoord2f(1, 1); glVertex3f(-D, +D, +D);
			glTexCoord2f(0, 1); glVertex3f(+D, +D, +D);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textures[(int)SKY::BACK].get());
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-D, -D, +D);
			glTexCoord2f(1, 0); glVertex3f(-D, -D, -D);
			glTexCoord2f(1, 1); glVertex3f(-D, +D, -D);
			glTexCoord2f(0, 1); glVertex3f(-D, +D, +D);
		glEnd();

		/* Top and Bottom */
		glBindTexture(GL_TEXTURE_2D, textures[(int)SKY::UP].get());
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-D, +D, -D);
			glTexCoord2f(1, 0); glVertex3f(+D, +D, -D);
			glTexCoord2f(1, 1); glVertex3f(+D, +D, +D);
			glTexCoord2f(0, 1); glVertex3f(-D, +D, +D);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textures[(int)SKY::DOWN].get());
		glBegin(GL_QUADS);
		glTexCoord2f(1, 1); glVertex3f(+D, -D, -D);
		glTexCoord2f(0, 1); glVertex3f(-D, -D, -D);
		glTexCoord2f(0, 0); glVertex3f(-D, -D, +D);
		glTexCoord2f(1, 0); glVertex3f(+D, -D, +D);
		glEnd();

		glDisable(GL_TEXTURE_2D);
}

