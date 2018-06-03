
#include "Board.h"


const short steps[SIZE][SIZE] = {
	{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
	{ -1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 4, 7, 7, 0, 0, 0, -1,-1,-1,-1,-1,-1,-1 },
	{ -1,-1,-1,-1,-1, 0, 0, 5, 4, 4, 8, 3, 3, 4, 6, 3, 0, 0, -1,-1,-1,-1,-1 },
	{ -1,-1,-1,-1, 0, 1, 4, 5, 1, 1, 1, 4, 5, 1, 7, 1, 3, 5, 0, -1,-1,-1,-1 },
	{ -1,-1,-1, 0, 4, 9, 4, 9, 6, 7, 5, 5, 5, 8, 7, 6, 6, 8, 5, 0, -1,-1,-1 },
	{ -1,-1, 0, 3, 7, 2, 9, 8, 3, 5, 6, 7, 3, 9, 1, 8, 7, 5, 8, 5, 0, -1,-1 },
	{ -1,-1, 0, 1, 4, 7, 8, 4, 2, 9, 2, 7, 1, 1, 8, 2, 2, 7, 6, 3, 0, -1,-1 },
	{ -1, 0, 7, 2, 1, 8, 5, 5, 3, 1, 1, 3, 1, 3, 3, 4, 2, 8, 6, 1, 3, 0, -1 },
	{ -1, 0, 4, 2, 6, 7, 2, 5, 2, 4, 2, 2, 5, 4, 3, 2, 8, 1, 7, 7, 3, 0, -1 },
	{ -1, 0, 4, 1, 6, 5, 1, 1, 1, 9, 1, 4, 3, 4, 4, 3, 1, 9, 8, 2, 7, 0, -1 },
	{  0, 4, 3, 5, 2, 3, 2, 2, 3, 2, 4, 2, 5, 3, 5, 1, 1, 3, 5, 5, 3, 7,  0 },
	{  0, 2, 7, 1, 5, 1, 1, 3, 1, 5, 3, 3, 2, 4, 2, 3, 7, 7, 5, 4, 2, 7,  0 },
	{  0, 2, 5, 2, 2, 6, 1, 2, 4, 4, 6, 3, 4, 1, 2, 1, 2, 6, 5, 1, 8, 8,  0 },
	{ -1, 0, 4, 3, 7, 5, 1, 9, 3, 4, 4, 5, 2, 9, 4, 1, 9, 5, 7, 4, 8, 0, -1 },
	{ -1, 0, 4, 1, 6, 7, 8, 3, 4, 3, 4, 1, 3, 1, 2, 3, 2, 3, 6, 2, 4, 0, -1 },
	{ -1, 0, 7, 3, 2, 6, 1, 5, 3, 9, 2, 3, 2, 1, 5, 7, 5, 8, 9, 5, 4, 0, -1 },
	{ -1,-1, 0, 1, 6, 7, 3, 4, 8, 1, 1, 1, 2, 1, 2, 2, 8, 9, 4, 1, 0, -1,-1 },
	{ -1,-1, 0, 2, 5, 4, 7, 8, 7, 5, 6, 1, 3, 5, 7, 8, 7, 2, 9, 3, 0, -1,-1 },
	{ -1,-1,-1, 0, 6, 5, 6, 4, 6, 7, 2, 5, 2, 2, 6, 3, 4, 7, 4, 0, -1,-1,-1 },
	{ -1,-1,-1,-1, 0, 2, 3, 1, 2, 3, 3, 3, 2, 1, 3, 2, 1, 1, 0, -1,-1,-1,-1 },
	{ -1,-1,-1,-1,-1, 0, 0, 7, 4, 4, 5, 7, 3, 4, 4, 7, 0, 0, -1,-1,-1,-1,-1 },
	{ -1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 3, 3, 4, 0, 0, 0, -1,-1,-1,-1,-1,-1,-1 },
	{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }
};


Board::Board(){
	boxSize = 40;
	for (int column = 0; column < SIZE; column++) {
		for (int row = 0; row < SIZE; row++) {
			
			Type type = Type::NORMAL;
			switch (steps[row][column]){
				case 0: type = Type::GOAL; break;
				case -1: type = Type::OUTSIDE; break;
			}
			boxs[row][column] = Box(this, column -11, row -11, steps[row][column], type, Status::NONE);
		}
	}
}


void Board::init() { loadSOILTexture("board0.png"); }

void Board::draw() {

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture);

	glDepthMask(GL_FALSE); //Make transparency
	
		
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-getHalbSize(), 0, -getHalbSize());
	glTexCoord2f(0.0, 1.0); glVertex3f(-getHalbSize(), 0, getHalbSize());
	glTexCoord2f(1.0, 1.0); glVertex3f(getHalbSize(), 0, getHalbSize());
	glTexCoord2f(1.0, 0.0); glVertex3f(getHalbSize(), 0, -getHalbSize());

	glEnd();
	
	glDepthMask(GL_TRUE);

	glDisable(GL_TEXTURE_2D);

	// draw grid
	 glColor3f(0.2f, 0.5f, 0.5f);

	 glPushMatrix();
	
	glTranslatef(-getHalbSize(), 0.1, -getHalbSize());
	glTranslatef(getHalbBoxSize(), 0, getHalbBoxSize());
	for (int column = 0; column < SIZE; column++) {
			for (int row = 0; row < SIZE; row++) {
				boxs[column][row].draw();
				glTranslatef(getBoxSize(), 0, 0);
			}
			glTranslatef(-getSize(), 0, 0);
			glTranslatef(0, 0, getBoxSize());
		}
	
	glPopMatrix();
	

	glPopMatrix();

}



Box * Board::getChildBox(Box * box, Directions direction) {
	int steps = box->getSteps();

	Position pos = box->getPosition();
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
			Box * newBox = this->getBox(newPos.x, newPos.y);
		
			if (newBox->getType() == Type::OUTSIDE) return NULL;
			if (newBox->getType() == Type::GOAL && i != steps) return NULL;

			if (i == steps) {
				if (newBox->getState() == State::CHECKED) {
					std::cout << "CHECKED \n ";
					return NULL;
				}
				else {
					std::cout << "UNCHECKED \n ";
					newBox->setState(State::CHECKED);
				}
				return newBox;
			}
		}
	}
	return NULL;
}
