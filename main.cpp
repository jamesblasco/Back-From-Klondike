
#include "core/GLCore.h"

#include "core/Game.h"
#include "core/Window.h"
#include "core/Perspective.h"

#include "core/MouseController.h"
#include "core/KeyboardController.h"

#include "FrameTimer.h"

#include "figures/Button.h"

Button button;

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

	InitFrameTimer(); // let the frame timer commence...

	glutMainLoop();

	return 0;
}


void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBackgroundColor(Color(167, 204, 237));

	glLoadIdentity();


	
	button.updateStatus(&window);
	button.render();
	//lines.updateStatus(&window);
	//lines.render();

	Perspective::draw();
	Game::draw();
	

	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cout << "OpenGL error: " << err;
		exit(1);
	}

	glutSwapBuffers();
}

void onIdle() {
	Game::update(); // update all instances animation
	glutPostRedisplay();
}

