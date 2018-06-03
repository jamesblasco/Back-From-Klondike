//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#include "KeyboardController.h"
#include "Game.h"

enum Keyboard::Arrows Keyboard::arrows;


void Keyboard::onKeyDown(unsigned char key, int x, int y) {

	switch (key) {
		case ESC: exit(1);
		case '1': game.reset(); game.solve(); game.changeMode(GameMode::AUTO); break;
		case '2': game.reset();  game.changeMode(GameMode::USER); break;
	
	}
	if (game.isUserMode()) {
		switch (key) {
			case 'w': game.next(N); break;
			case 'e': game.next(NE); break;
			case 'd': game.next(E); break;
			case 'c': game.next(SE); break;
			case 'x': game.next(S); break;
			case 'z': game.next(SW); break;
			case 'a': game.next(W); break;
			case 'q': game.next(NW); break;
		}
	} else if(game.isAutoMode()) {
		switch (key) {
			case ' ': game.nextStepInSolution(); break;
		}
	}
	Game::update();
	glutPostRedisplay();
}

void Keyboard::onArrowDown(int key, int x, int y) {
	Keyboard::arrows = (Keyboard::Arrows)key;
	Game::update();
	glutPostRedisplay();
}
