//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#include "Game.h"
#include "Perspective.h"
#include "../figures/Clouds.h"
#include <sstream>
#include <string>
#include <sstream>
#include <string>


//Default initializers
Board Game::board;
Yoshi Game::yoshi; 
GameMode Game::mode = GameMode::USER; // Default GameMode - USER 
Path Game::path = board.getStartBox(); // Init path with start box
std::list<Box *> Game::solution = {}; 
std::list<Figure *> Game::decorations = { new Clouds() }; // Init path with start box


void Game::init() {
	yoshi.init(); // Init yoshi textures
	board.init(); // Init board textures
}

void Game::draw() {

	Box * current = path.getCurrentBox();
	Position pos = current->getPosition();

	//Draw Info mode box
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

	
	Perspective::draw(); //Draw perspective

	yoshi.draw(); //Draw yoshi
	
	//Draw board and decorations
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
		yoshi.changeAnim();
		if (newBox->getType() == Type::GOAL) yoshi.setAnim(7);
		path.addBox(newBox);
		return newBox;
	} else return NULL;
}

 Box * Game::nextStepInSolution(){
	 if (solution.size() != 0) {
		 path.getCurrentBox()->setStatus(Status::PAST);
		 solution.front()->setStatus(Status::ACTIVE);
		 yoshi.changeAnim();
		 path.addBox(solution.front());
		 solution.erase(solution.begin());
		 if(solution.size() == 0) yoshi.setAnim(7);
		 return solution.front();
	 } else {
		 return NULL;
	 }
	 
 }

 void Game::reset() {
	 board.reset();
	 path = board.getStartBox();
	 yoshi.setAnim(0);
 }

void Game::changeMode(GameMode m) { mode = m; }
void Game::update() {
	yoshi.update();
	glutPostRedisplay();
}


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

void Game::solve() {
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