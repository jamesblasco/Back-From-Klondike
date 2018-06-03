
#include "Game.h"
#include "Perspective.h"
#include "../figures/Algorithm.h"
#include "../figures/Clouds.h"
#include <sstream>
#include <string>
#include <sstream>
#include <string>


Board Game::board;
Yoshi Game::yoshi; 
GameMode Game::mode = GameMode::USER;
Path Game::path = board.getStartBox();
std::list<Box *> Game::solution = {};
std::list<Figure *> Game::decorations = { new Clouds() };


void Game::init() {
	//for (Figure* figure : decorations) figure->init();
	yoshi.init();
	board.init();
}

void Game::draw() {

	Box * current = path.getCurrentBox();
	Position pos = current->getPosition();
	
	

	glPushMatrix();
	glTranslatef(-200, 150, -400);
	
	glColor(Color(255, 255, 255, 0.5));
	
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-10, -10, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-10, 10, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(120, 10, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(120, -10, 0);
	glEnd();

	glTranslatef(10, -12, 20);
	glColor(Color(25, 76, 25));
	glPrint(0, 0, 0, (char *)(mode == GameMode::USER ? "USER MODE" : "SOLUTION MODE"));

	glPopMatrix();

	Perspective::draw();

	yoshi.draw();
	glPushMatrix();
		glTranslatef(-pos.x*board.getBoxSize(), 0, -pos.y*board.getBoxSize());
		for (Figure* figure : decorations) figure->draw(); // first ones -- back
		board.draw();
	glPopMatrix();

}

 Box * Game::next(Directions direction) {
	Box * current = path.getCurrentBox();
	Box * newBox  = current->getChildBox(direction);

	if(newBox) {
		current->setStatus(Status::PAST);
		newBox->setStatus(Status::ACTIVE);
		path.addBox(newBox);
		return newBox;
	} else return NULL;
}

 Box * Game::nextStepInSolution(){

	 std::cout << solution.size();
	 if (solution.front()) {
		 path.getCurrentBox()->setStatus(Status::PAST);
		 solution.front()->setStatus(Status::ACTIVE);
		 
		 path.addBox(solution.front());
		 solution.erase(solution.begin());
		 return solution.front();
	 }
	 return NULL;
 }

 void Game::reset() {
	 board.reset();
	 path = board.getStartBox();
 }

void Game::changeMode(GameMode m) { mode = m; }
void Game::update() {yoshi.update(); }

void Game::buildSolution(Box* goal){
	Box * node = goal;
	int i = 0;
	while (node->getPosition()!=Position(0,0)) {
		solution.push_front(node);
		i++;
		node = node->getParent();
	}

	//std::cout << "Tamaño de solucion final" << i;
}

void Game::solver() {
	std::list<Box*> open;
	std::list<Box*> aux;

	open.push_back(board.getStartBox());
	int i = 0;
	while (open.size() > 0) {
		for (Box* node : open) {
			//std::cout << node->getSteps() << "\n";
			for (Directions dir : { N, NE, E, SE, S, SW, W, NW }) {
				Box* child = node->getChildBox(dir, true);
				if (child != NULL) {
					child->setParent(node);
					if (child->getType() == Type::GOAL) return buildSolution(child);
					aux.push_back(child);
				}
			}
		}
		i++;
		//std::cout<< "\nNivel " << i << "\n";
		open = aux;
		aux.clear();
	}
	
	std::cout << "no hay solucion:" << open.size();
}