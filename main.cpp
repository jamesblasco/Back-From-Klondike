
#include <stdlib.h>
#include <iostream>
#include "glut.h"

#include "GLController.h"
#include "FrameTimer.h"


int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Maya Camera");

	glutDisplayFunc(onDisplay);
	glutReshapeFunc(onResize);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	glutKeyboardFunc(onKeyboardDown);
	glutIdleFunc(onIdle);

	
		
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	
	init();

	InitFrameTimer(); // let the frame timer commence...

	glutMainLoop();

	return 0;
}


