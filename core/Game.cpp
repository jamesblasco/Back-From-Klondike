//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#include "Game.hpp"
#include "Perspective.hpp"
#include "../figures/Clouds.hpp"
#include <sstream>
#include <string>
#include <sstream>
#include <string>


//Default initializers
Board Game::board;
Yoshi Game::yoshi; 
SkyBox Game::skybox;
Logo Game::logo;
GameMode Game::mode = GameMode::USER; // Default GameMode - USER 
Path Game::path = board.getStartBox(); // Init path with start box
std::list<Box *> Game::solution = {}; 
std::list<Figure *> Game::decorations = { new Clouds() }; // Init path with start box

// Init figures
void Game::init() {
	yoshi.init(); // Init yoshi textures
	board.init(); // Init board textures
	skybox.init(); // Init skybox textures
	logo.init(); // Init logo textures
}
// Update figures
void Game::update() {
	yoshi.update();
	glutPostRedisplay();
}
// Reset default values
void Game::reset() {
	board.reset(); //set Status from Boxes as UNCHECKED
	path = board.getStartBox(); //clean path
	yoshi.setAnim(0); //set default anim
}

void Game::changeMode(GameMode m) { mode = m; }

// Draws all figures
void Game::draw() {

	Box * current = path.getCurrentBox(); // Current Box in Path
	Position pos = current->getPosition(); // Position of current Box in Path

	//Draw MODE info box
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
	yoshi.render(); //Draw yoshi
	skybox.render(); //Draw sky
	logo.render(); //Draw logo
	for (Figure* figure : decorations) figure->render(); //Decorations
	
	glTranslatef(-pos.x*board.getBoxSize(), 0, -pos.y*board.getBoxSize()); // Center board to yoshi position
	board.draw();//Draw board

}

// Get next box given a direction (USER MODE)
 Box * Game::next(Directions direction) {
	Box * current = path.getCurrentBox();
	Box * newBox  = current->getChildBox(direction); //get new box

	if(newBox) {  //IF  NEW BOX EXITS
		current->setStatus(Status::PAST); //set Past state to previus box
		newBox->setStatus(Status::ACTIVE);  //set Active state to new box
		yoshi.changeAnim(); 
		if (newBox->getType() == Type::GOAL) yoshi.setAnim(7); 
		path.addBox(newBox); // Adds new box to the path
		return newBox;
	} else return NULL;
}

 // Get next box from solution (AUTO MODE)
 Box * Game::nextStepInSolution(){
	 if (solution.size() != 0) {  //if solution has not been copied all to path
		 path.getCurrentBox()->setStatus(Status::PAST); //set Past state to previus box
		 solution.front()->setStatus(Status::ACTIVE); //set Active state to new box
		 yoshi.changeAnim();
		 path.addBox(solution.front()); // Adds new box to the path
		 solution.erase(solution.begin());  // Remove new box from solution
		 if(solution.size() == 0) yoshi.setAnim(7);
		 return solution.front();
	 } else {
		 return NULL; //if there is not next box return null
	 }
	 
 }

 // Build solution given the GOAL box
 void Game::buildSolution(Box* goal){
	 solution.clear();
	Box * node = goal;
	while (node->getPosition()!=Position(0,0)) { //Check parents until is starter box
		solution.push_front(node);
		node = node->getParent();
	}
	std::cout << "Solucion encontrada en " << solution.size() << " movimientos\n";
}
//Solver
void Game::solve() {
	std::list<Box*> open;
	std::list<Box*> aux;
	open.push_back(board.getStartBox());

	std::cout << "Buscando solucion" << "\n";
	
	int level = 0;
	while (open.size() > 0) {
		for (Box* node : open) { //Search for childs in every box of the level
			for (Directions dir : { N, NE, E, SE, S, SW, W, NW }) { //Look childs in every  direction
				Box* child = node->getChildBox(dir, true); //Look child in a  direction
				if (child != NULL) { // Check if avaible child exist
					child->setParent(node); // Add parent relation
					if (child->getType() == Type::GOAL) return buildSolution(child); // Looks if box is GOAL and build solution
					aux.push_back(child); //Add box to a new level search
				}
			}
		}
		level++; std::cout<< "Nivel " << level << " de busqueda\n"; // Indicates the depth level of the search
		open = aux;   //Add new level to search
		aux.clear();  //Clear aux list
	}
	
	std::cout << "No hay solucion :(";
}