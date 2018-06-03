//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#include "Box.h"
#include "Board.h"
#include "../core/Game.h"

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



Box * Box::getChildBox(Directions direction, bool trackState) {
	int steps = this->getSteps();

	Position pos = this->getPosition();
	Position newPos;

	for (int i = 1; i <= steps; i++) {

		switch (direction) {
		case N: newPos = Position(pos.x, pos.y - i); break;
		case NE: newPos = Position(pos.x + i, pos.y - i); break;
		case E: newPos = Position(pos.x + i, pos.y); break;
		case SE: newPos = Position(pos.x + i, pos.y + i); break;
		case S: newPos = Position(pos.x, pos.y + i); break;
		case SW: newPos = Position(pos.x - i, pos.y + i); break;
		case W: newPos = Position(pos.x - i, pos.y); break;
		case NW: newPos = Position(pos.x - i, pos.y - i); break;
		default: return NULL;
		}

		Position from = Position(-11, -11);
		Position to = Position(11, 11);

		if (Position::isInsideArea(newPos, from, to)) {
			Box * newBox = board->getBox(newPos.x, newPos.y);

			if (newBox->getType() == Type::OUTSIDE) return NULL;
			if (newBox->getType() == Type::GOAL && i != steps) return NULL;

			if (i == steps) {
				if (newBox->getState() == State::CHECKED && trackState) {
					std::cout << "CHECKED \n ";
					return NULL;
				}
				else {
					std::cout << "UNCHECKED \n ";
					newBox->setState(State::CHECKED);
				}
				
				std::cout << " " << newBox->getSteps();

				return newBox;
			}
		}
	}
	return NULL;
}


