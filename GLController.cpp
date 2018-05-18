#include "GLController.h"
#include "GLFigure.h"

#include "GLUtils.h"
#include "Yoshi.h"


Position pos = Position();
Position rot = Position(0, 0.001f);
Position mouse = Position();
float zoom = 200.0f;
unsigned char Buttons[3] = { 0 };

Snowman snowman;
Yoshi yoshi;

void init() {
	yoshi.init();
	glColor3f(1, 1, 1);
}


void onMouse(int button, int state, int x, int y) {
	bool isPressed = (state == GLUT_DOWN) ? true : false;
	mouse = Position(x, y);
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		Buttons[0] = isPressed;	break;
	case GLUT_MIDDLE_BUTTON:
		Buttons[1] = isPressed;	break;
	case GLUT_RIGHT_BUTTON:
		Buttons[2] = isPressed;	break;
	default:
		break;
	}
	glutPostRedisplay();
};


void onMotion(int x, int y) {
	Position newer = Position(x, y);
	Position diff = newer - mouse;
	mouse = newer;

	if (Buttons[0] && Buttons[1]) {
		//zoom -= (float) 0.05f * diff.x;
	}
	else if (Buttons[0]) {
		rot.x += (float) 0.5f * diff.y;
		rot.y += (float) 0.5f * diff.x;
	}
	else	if (Buttons[1]) {
		pos.x += (float) 0.05f * diff.x;
		pos.y -= (float) 0.05f * diff.y;
	}
	glutPostRedisplay();
}



void onKeyboardDown(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
	case ESC:
		exit(1);
	case 'a':
		/* do something */;
		break;
	}
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

	glLoadIdentity();

	glTranslatef(0, 0, -zoom);
	glTranslatef(0, 0, 0);
	glRotatef(rot.x, 1, 0, 0);
	glRotatef(rot.y, 0, 1, 0);

	glPushMatrix();
	// draw grid
	glColor3f(0.2f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		for (int i = -100; i <= 110; i+= 10) {
			glVertex3f(i -5 , 0, -105);
			glVertex3f(i -5, 0, 105);

			glVertex3f(105, 0, i-5);
			glVertex3f(-105, 0, i-5);
		}
		glEnd();
	glPopMatrix();


	//glTranslatef(0, 0, 0);
	snowman.draw();
	//glTranslatef(0, 0, 0);
		
	

	yoshi.draw();

	glutSwapBuffers();
}



void onIdle() {
	yoshi.update(); // update all instances animation
	glutPostRedisplay();
}