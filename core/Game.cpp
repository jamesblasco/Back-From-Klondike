
#include "Game.h"
#include "../figures/Algorithm.h"
#include "../figures/Clouds.h"


Board Game::board;
Yoshi Game::yoshi; 
std::list<Figure *> Game::decorations = { new Clouds() };
std::list<Box *> Game::solution = {  };
Path Game::path = board.getStartBox();


void Game::init() {
	//for (Figure* figure : decorations) figure->init();
	yoshi.init();
	board.init();
	solver();
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

		if (newBox->getType() == Type::OUTSIDE) return NULL;
		current->setStatus(Status::PAST);
		newBox->setStatus(Status::ACTIVE);
		path.addBox(newBox);
		return newBox;
	}
	return NULL;
}

void Game::update() {yoshi.update(); }

void Game::buildSolution(Box* goal){
	Box * node = goal;
	int i = 0;
	while (node->getPosition()!=Position(0,0)) {
		solution.push_front(node);
		i++;
		node = node->getParent();
	}
	std::cout << "Tamaño de solucion final" << i;
}

void Game::solver() {
	std::list<Box*> open;
	std::list<Box*> aux;

	open.push_back(board.getStartBox());
	int i = 0;
	while (open.size() > 0) {
		for (Box* node : open) {
			std::cout << node->getSteps() << "\n";
			for (Directions dir : { N, NE, E, SE, S, SW, W, NW }) {
				Box* child = board.getChildBox(node, dir);
				if (child != NULL) {
					child->setParent(node);
					if (child->getType() == Type::GOAL) return buildSolution(child);
					aux.push_back(child);
				}
			}
		}
		i++;
		std::cout<< "\nNivel " << i << "\n";
		open = aux;
		aux.clear();
	}
	
	std::cout << "no hay solucion:" << open.size();
}