#include "GLController.h"

#include "Game.h"


Perspective perspective;
Mouse mouse;
Game game;

void init() { game.init(); }


void onMouse(int button, int state, int x, int y) {
	mouse.pos = Position(x, y);
	mouse.button = (Buttons) button; //Button enumeration uses GL BUTTONS definitions
	if (state != GLUT_DOWN) mouse.button = Buttons::NONE;
	glutPostRedisplay();
};


void onMotion(int x, int y) {
	Position diff = mouse.update(x, y);

	if (mouse.button == Buttons::LEFT) 	perspective.move(diff);
	else if (mouse.button == Buttons::RIGHT) perspective.rotate(diff);

	glutPostRedisplay();
}



void onKeyboardDown(unsigned char key, int x, int y) {
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

void onArrowDown(int key, int x, int y) {
	std::cout << "key" << key;
	mouse.arrows = (Arrows)key;
	glutPostRedisplay();
}

void onResize(int w, int h) {
	if (w == 0)	h = 1; // prevent divide by 0 error when minimised
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 5, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBackgroundColor(Color(167, 204, 237));
	//glClearColor(0, 0, 0, 1.0);
	
	glLoadIdentity();


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	perspective.draw();
	game.draw();

	glDisable(GL_BLEND);
	
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cout << "OpenGL error: " << err;
		exit(1);
	}

	glutSwapBuffers();
}



void onIdle() {
	game.update(); // update all instances animation
	glutPostRedisplay();
}