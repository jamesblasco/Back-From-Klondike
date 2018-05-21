#include "Game.h"
#include <string>
#include <sstream>
#include <string>
#include <sstream>


Box::Box(Board* parent, int i, int j, int steps, Type type, Status status) {
	this->parent = parent;
	this->pos = Position(i, j);
	this->steps = steps;
	this->type = type;
	this->status = status;
}
void Box::draw() {
	std::ostringstream oss;
	oss << steps;
	std::string var = oss.str().c_str();
	glPrint(0, 0, 0, (char *)oss.str().c_str());
	switch (type){
		case Type::NORMAL:
			switch (status) {
				case Status::ACTIVE: glColor(Color(170, 255, 170, 0.5)); break;
				case Status::PAST:   glColor(Color(150, 150, 150, 0.5)); break;
				case Status::NONE: default:	return;
			}
			break;
		case Type::GOAL:
			glColor(Color(0, 255, 0, 1));
			break;
		case Type::OUTISDE:
		default:
			return;
	}
	
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-parent->getHalbBoxSize(), 0, -parent->getHalbBoxSize());
	glTexCoord2f(0.0, 1.0); glVertex3f(-parent->getHalbBoxSize(), 0, parent->getHalbBoxSize());
	glTexCoord2f(1.0, 1.0); glVertex3f(parent->getHalbBoxSize(), 0, parent->getHalbBoxSize());
	glTexCoord2f(1.0, 0.0); glVertex3f(parent->getHalbBoxSize(), 0, -parent->getHalbBoxSize());

	glEnd();

	
	glFlush();
}