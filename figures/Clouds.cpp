#include "Clouds.h"
#include "Cloud.h"

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