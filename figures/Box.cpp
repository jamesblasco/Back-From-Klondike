#include "Box.h"
#include "Board.h"
#include "../core/Game.h"
#include <string>
#include <sstream>
#include <string>
#include <sstream>




Box::Box(Board* board, int i, int j, int steps, Type type, Status status) {
	this->board = board;
	this->pos = Position(i, j);
	this->steps = steps;
	this->type = type;
	this->status = status;
	this->state = State::UNCHECKED;
	this->parent = NULL;
}

void Box::setParent(Box * p){	parent = p;}
Box * Box::getParent() { return parent; }

void Box::draw() {
	/*std::ostringstream oss;
	oss << steps;
	std::string var = oss.str().c_str();
	glPrint(0, 0, 0, (char *)oss.str().c_str());*/
	switch (type){
		case Type::NORMAL:
			switch (status) {
				case Status::ACTIVE: glColor(Color(29, 179, 29, 0.8)); break;
				case Status::PAST: { 
					glColor(Color(150, 150, 150, 0.5)); 
					glPushMatrix();
					glColor3f(0.0f, 1.0f, 0.0f);
					glTranslatef(0, 5, 0);
					board->jump(5, 3);
					glutSolidSphere(10, 20, 20);
					glPopMatrix();
					
				}
				case Status::NONE: default:	return;
			}
			break;
		case Type::GOAL:
			glColor(Color(0, 255, 0, 1));
			break;
		case Type::OUTSIDE:
		default:
			return;
	}
	
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-board->getHalbBoxSize(), 0, -board->getHalbBoxSize());
	glTexCoord2f(0.0, 1.0); glVertex3f(-board->getHalbBoxSize(), 0, board->getHalbBoxSize());
	glTexCoord2f(1.0, 1.0); glVertex3f(board->getHalbBoxSize(), 0, board->getHalbBoxSize());
	glTexCoord2f(1.0, 0.0); glVertex3f(board->getHalbBoxSize(), 0, -board->getHalbBoxSize());

	glEnd();

	
	glFlush();
}

