#ifndef BOX_H
#define BOX_H

#include "../core/GLFigure.h"

class Board;

enum class Status { NONE, ACTIVE, PAST }; // ACTIVE figure is above box, PAST figure was above box
enum class Type { NORMAL, GOAL, OUTSIDE };
enum class State { UNCHECKED, CHECKED };// For solver
enum Directions { N, NE, E, SE, S, SW, W, NW };


class Box : public Figure {
	Board* board;
	Position pos; //Relative position
	int steps;
	Status status;
	Type type;
	State state;
	Box * parent;

public:
	Box() {};
	Box(Board* parent, int i = 0, int j = 0, int steps = 0, Type type = Type::NORMAL, Status status = Status::NONE);

	void draw();

	void setParent(Box*);
	Box* getParent();

	Position getPosition() { return pos; };
	void setPosition(Position pos) { this->pos = pos; };
	Status getStatus() { return status; };
	void setStatus(Status status) { this->status = status; };
	int getSteps() { return steps; };
	Type getType() { return type; };
	State getState() { return state; };
	void setState(State state) { this->state = state; };

	Box * getChildBox(Directions, bool = false);
};

#endif