#include "GLController.h"
#include "GLFigure.h"
#include "FrameTimer.h"
#include "GLAdvancedFigure.h"
#include "GLUtils.h"


Position pos = Position();
Position rot = Position(0, 0.001f);
Position mouse = Position();
float zoom = 100.0f;
unsigned char Buttons[3] = { 0 };

MD2Model md2File;
unsigned int md2Texture;

void init() {
	md2File.Load("tris.md2");
	// write memory usage
	std::cout << "memory usage " << (md2File.GetDataSize() / 1024.0f) << "kb\n";
	md2Texture = MakeTexture("yoshi.pcx");
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


void onMotion(int x, int y)
{
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



void onKeyboardDown(unsigned char key, int x, int y){
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


void onResize(int w, int h){
	if (w == 0)	h = 1; // prevent divide by 0 error when minimised
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 5, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

Snowman snowman = Snowman();

void onDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	glTranslatef(0, 0, -zoom);
	glTranslatef(0, 0, 0);
	glRotatef(rot.x, 1, 0, 0);
	glRotatef(rot.y, 0, 1, 0);



	
	// apply texture
	glBindTexture(GL_TEXTURE_2D, md2Texture);

	// render all model instances loaded
	md2File.Render();

	glTranslatef(0, 0, -zoom);
	glTranslatef(10, 10, 0);
	md2File.Render();

	glutSwapBuffers();
}


int frameRateCounter = 0;
void onIdle() {
	
	// get time since last frame
	float dt = FrameTime();
	
	md2File.Update(dt); // update all instances animation
		
	// only output the frame rate every 100 frames...
	if (++frameRateCounter>500) {
		std::cout << (1.0f / dt) << " fps\r";
		frameRateCounter = 0;
	}
	glutPostRedisplay();
}