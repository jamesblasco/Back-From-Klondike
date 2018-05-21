#include "Game.h"

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

Clouds::Clouds() {
	figures = { new Cloud(), new Cloud(), new Cloud(), new Cloud(),  new Cloud(), new Cloud(), new Cloud(), new Cloud(),  new Cloud(), new Cloud() };
}

void Clouds::draw() {

	int i = 0;
	glPushMatrix();
	for (Figure* figure : figures) {
		switch (i%4){
		default:
			rotate(Y, 1, 40*(i%4));
			case 0:
				glTranslatef(15, 2, 0);
				figure->rotate(Y, 0.0001);
				break;
			case 1:
				glTranslatef(15, 10, 0);
				break;
			case 2:
				glTranslatef(50, -12, 0);
				figure->rotate(Y, 0.0001);
				break;
			break;
		}

		figure->draw();
		i++;
	}
	glPopMatrix();

}