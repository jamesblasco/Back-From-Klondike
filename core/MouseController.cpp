#include "MouseController.h"
#include "Perspective.h"

enum Mouse::Buttons Mouse::button;
class Position2D Mouse::pos;

Mouse::Mouse() {
	pos = Position2D();
	button = Buttons::NONE;
}

Position2D Mouse::update(int x, int y) {
	Position2D newer = Position2D(x, y);
	Position2D diff = newer - pos;
	pos = newer;
	return diff;
}

void Mouse::onClick(int button, int state, int x, int y) {
	//window.setCursor(x, y);
	mouse.pos = Position(x, y);
	mouse.button = (Buttons)button; //Button enumeration uses GL BUTTONS definitions
	if (state != GLUT_DOWN) mouse.button = Buttons::NONE;
	glutPostRedisplay();
};

void Mouse::onClickMotion(int x, int y) {
	Position diff = mouse.update(x, y);
	if (mouse.button == Buttons::LEFT) 	perspective.move(diff);
	else if (mouse.button == Buttons::RIGHT) perspective.rotate(diff);
	glutPostRedisplay();
}


void Mouse::onMotion(int x, int y) { mouse.update(x, y); }



Position Mouse::worldPosition(Position *start) {

	double x, y, z;

	double modelViewMatrix[16];
	double projectionMatrix[16];
	int viewport[4];

	glGetDoublev(GL_MODELVIEW_MATRIX, modelViewMatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
	glGetIntegerv(GL_VIEWPORT, viewport);

	gluUnProject(pos.x, pos.y, 0.0f,
		modelViewMatrix, projectionMatrix, viewport,
		&x, &y, &z);

	Position mouseRay = Position((float)x, (float)y, (float)z);
	gluUnProject(pos.x, pos.y, 1.0f,
		modelViewMatrix, projectionMatrix, viewport,
		&x, &y, &z);
	*start = mouseRay;
	return Position((float)x, (float)y, (float)z) - *start;
}


class PickingRay {
private:
	Position clickPosInWorld =  Position();
	Position direction =  Position();

	/**
	* Computes the intersection of this ray with the X-Y Plane (where Z = 0)
	* and writes it back to the provided vector.
	*/
public:
	Position intersectionWithXyPlane()
	{
	
		float s = -clickPosInWorld.z / direction.z;
		return Position(clickPosInWorld.x + direction.x*s, clickPosInWorld.y + direction.y*s, 0);

	}

	Position getClickPosInWorld() {
		return clickPosInWorld;
	}
	Position getDirection() {
		return direction;
	}
};