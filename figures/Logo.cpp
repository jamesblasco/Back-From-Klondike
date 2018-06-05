#include "Logo.h"

//Load texture
void Logo::init() {	texture.loadSOILTexture("textures/logo.png");}

//Draw logo
void Logo::draw() {
	int W = 3128;	int H = 518;
	
	glTranslatef(0, 200, -3000);
	
	glEnable(GL_TEXTURE_2D); //Enable texture
	glDepthMask(GL_FALSE); //Make transparency

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture.get());

	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(+W / 2, +H / 2, 0);
		glTexCoord2f(1, 0); glVertex3f(-W / 2, +H / 2, 0);
		glTexCoord2f(1, 1);  glVertex3f(-W/2, -H/2,0);
		glTexCoord2f(0, 1); glVertex3f(+W / 2, -H / 2, 0);
	glEnd();
	
	glDepthMask(GL_TRUE);
	glDisable(GL_TEXTURE_2D);

}

