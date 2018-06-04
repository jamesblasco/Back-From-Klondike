//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef BOX_H
#define BOX_H

#include "../core/GLFigure.h"

class Board; 

// Status of box relative to the current path
enum class Status { 
	NONE,
	ACTIVE, //Figure is above box
	PAST //Figure has passed through here
}; 

// Difference type of class
enum class Type { 
	NORMAL, 
	GOAL, //Box where you win
	OUTSIDE   //Can not step inside
}; 

// Status of box relative to the resolution algorithm
enum class State { UNCHECKED, CHECKED };

// Cardinal points for indicate the directions to which the figure can go
enum Directions { N, NE, E, SE, S, SW, W, NW };



//
// Box
//
// Extends: Figure(is drawn with opengl)
// Each box has its steps and other properties to draw according to a goal box or has been passed over
//
class Box : public Figure {
	Board* board; // Pointer to board
	Position pos; // Relative position on the board
	int steps; // number of steps yoshi can take

	Status status; // Status of box relative to the current path(NONE, ACTIVE, PAST)
	Type type; // Difference type of class (NORMAL, GOAL, OUTSIDE)

	//Used in resolution algorithm
	State state; // Status of box relative to the resolution algorithm
	Box * parent; // Parent box in resolution algorithm
	

public:
	Box() {}; //Default init
	// Init board with default values
	Box(Board* parent, int i = 0, int j = 0, int steps = 0, 
		Type type = Type::NORMAL, Status status = Status::NONE); 

	void draw(); // Draw box on above board (Only for PAST, ACTIVE and GOAL boxes)

	Position getPosition() { return pos; }; // Get relative position
	void setPosition(Position pos) { this->pos = pos; }; // Set relative position
	
	Status getStatus() { return status; }; // Get status
	void setStatus(Status status) { this->status = status; }; // Set status

	int getSteps() { return steps; }; // Get Steps
	Type getType() { return type; }; // Get Type
	
	//Used in resolution algorithm
	State getState() { return state; }; // Get current state
	void setState(State state) { this->state = state; }; // Set current state
	Box* getParent(); // Get parent box 
	void setParent(Box*); // Set parent box 
	Box * getChildBox(Directions, bool = false); // Get child box, bool used if want track the state
};

#endif