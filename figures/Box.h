#ifndef BOX_H
#define BOX_H

#include "../core/GLFigure.h"

class Board;

enum class Status { NONE, ACTIVE, PAST }; // ACTIVE figure is above box, PAST figure was above box
enum class Type { NORMAL, GOAL, OUTISDE };
enum class Search { UNCHECKED, CHEKING, CLOSED, OPEN };

class Box : public Figure {
	Board* parent;
	Position pos; //Relative position
	int steps;
	Status status;
	Type type;
public:
	Box() {};
	Box(Board* parent, int i = 0, int j = 0, int steps = 0, Type type = Type::NORMAL, Status status = Status::NONE);

	void draw();

	Position getPosition() { return pos; };
	void setPosition(Position pos) { this->pos = pos; };
	Status getStatus() { return status; };
	void setStatus(Status status) { this->status = status; };
	int getSteps() { return steps; };
	Type getType() { return type; };
};

#endif