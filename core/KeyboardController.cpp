
#include "KeyboardController.h"
#include "Game.h"

enum Keyboard::Arrows Keyboard::arrows;

void Keyboard::onKeyDown(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
	case ESC: exit(1);
	case '1': game.next(Directions::N); break;
	case '2': game.next(Directions::NE); break;
	case '3': game.next(Directions::E); break;
	case '4': game.next(Directions::SE); break;
	case '5': game.next(Directions::S); break;
	case '6': game.next(Directions::SW); break;
	case '7': game.next(Directions::W); break;
	case '8': game.next(Directions::NW); break;
	case 'a':
		/* do something */;
		break;
	}
	glutPostRedisplay();
}

void Keyboard::onArrowDown(int key, int x, int y) {
	Keyboard::arrows = (Keyboard::Arrows)key;
	glutPostRedisplay();
}
