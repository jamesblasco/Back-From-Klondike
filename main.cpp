//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#include "core/GLCore.h"

#include "core/Game.h"
#include "core/Window.h"

#include "core/MouseController.h"
#include "core/KeyboardController.h"


void onDisplay();
void onIdle();

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Klondike");

	glutDisplayFunc(onDisplay);
	glutIdleFunc(onIdle);

	glutReshapeFunc(Window::onResize);
;
	glutSpecialFunc(Keyboard::onArrowDown);
	glutKeyboardFunc(Keyboard::onKeyDown);

	glutMouseFunc(Mouse::onClick);
	glutMotionFunc(Mouse::onClickMotion);
	glutPassiveMotionFunc(Mouse::onMotion);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glPointSize(5.0);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	Game::init();

	glutMainLoop();

	return 0;
}


void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBackgroundColor(Color(167, 204, 237));

	glLoadIdentity();

	Game::draw();
	Game::update();

	glutSwapBuffers();
}

// update all instances animation
void onIdle() { Game::update(); }

