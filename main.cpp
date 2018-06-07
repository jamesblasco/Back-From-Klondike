//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#include "core/GLCore.hpp"

#include "core/Game.hpp"
#include "core/Window.hpp"

#include "core/MouseController.hpp"
#include "core/KeyboardController.hpp"


void onDisplay();
void onIdle();
void glutConfig(int argc, char* argv[]);

#define NAME "Klondike"
#define W 640
#define H 480

int main(int argc, char* argv[]) {

	glutConfig(argc, argv);
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

void glutConfig(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(NAME);

	glutDisplayFunc(onDisplay);
	glutIdleFunc(onIdle);

		glutReshapeFunc(Window::onResize);

		glutSpecialFunc(Keyboard::onArrowDown);
		glutKeyboardFunc(Keyboard::onKeyDown);

		glutMouseFunc(Mouse::onClick);
		glutMotionFunc(Mouse::onClickMotion);
		glutPassiveMotionFunc(Mouse::onMotion);

	glEnable(GL_DEPTH_TEST);
	glPointSize(5.0);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	// Set lighting intensity and color
	GLfloat qaAmbientLight[] = { 0.415,0.717, 0.9, 0.1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	
	// Light source position
	GLfloat qaLightPosition[] = { 0, 1, 0, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	GLfloat globalAmbient[] = { 0,0,0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
}



