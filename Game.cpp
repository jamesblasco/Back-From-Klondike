#include "Game.h"


Game::Game():
	path(board.getStartBox()),
	decorations({ new Clouds() }) {};

void Game::init() {
	//for (Figure* figure : decorations) figure->init();
	yoshi.init();
	board.init();
}

void Game::draw() {
	

	Box * current = path.getCurrentBox();
	Position pos = current->getPosition();
	
	yoshi.draw();
	glPushMatrix();
		glTranslatef(-pos.x*board.getBoxSize(), 0, -pos.y*board.getBoxSize());
		for (Figure* figure : decorations) figure->draw(); // first ones -- back
		board.draw();
	glPopMatrix();
	
	

}
 Box * Game::next(Directions direction) {
	
	Box * current = path.getCurrentBox();
	
	int steps = current->getSteps();
	Position pos = current->getPosition();
	std::cout << "pos x:" << pos.x << " y:" << pos.y << "\n";
	Position newPos;
	
	switch (direction) {
		case Directions::N: newPos = Position(pos.x, pos.y - steps); break;
		case Directions::NE: newPos = Position(pos.x + steps, pos.y - steps); break;
		case Directions::E: newPos = Position(pos.x + steps, pos.y); break;
		case Directions::SE: newPos = Position(pos.x + steps, pos.y + steps); break;
		case Directions::S: newPos = Position(pos.x, pos.y + steps); break;
		case Directions::SW: newPos = Position(pos.x - steps, pos.y + steps); break;
		case Directions::W: newPos = Position(pos.x - steps, pos.y); break;
		case Directions::NW: newPos = Position(pos.x - steps, pos.y - steps); break;
		default: return NULL;
	}

	Position from = Position(-11, -11);
	Position to = Position(11, 11);

	if (Position::isInsideArea(newPos, from, to)) {
		std::cout << "new x:" << newPos.x << " y:" << newPos.y << "\n";
		Box * newBox = board.getBox(newPos.x, newPos.y);

		if (newBox->getType() == Type::OUTISDE) return NULL;
		current->setStatus(Status::PAST);
		newBox->setStatus(Status::ACTIVE);
		path.addBox(newBox);
		return newBox;
	}
	return NULL;
}

void Game::update() {yoshi.update(); }

