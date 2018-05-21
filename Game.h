#ifndef GAME_H
#define GAME_H

#include "GLUtils.h"
#include "GLFigure.h"
#include "MD2Model.h"
#include <list>


enum class Status { NONE, ACTIVE, PAST }; // ACTIVE figure is above box, PAST figure was above box
enum class Type { NORMAL, GOAL, OUTISDE }; 
enum class Search { UNCHECKED, CHEKING, CLOSED, OPEN };
#define SIZE 23


class Board;

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

class Board : public Figure, Texture {
	int boxSize;
public:
	
	Box boxs[SIZE][SIZE];

	Board();
	void init();
	void draw();
	float getSize() { return boxSize * SIZE; };
	float getBoxSize() { return (float)boxSize; };
	float getHalbSize() { return boxSize * SIZE / 2; };
	float getHalbBoxSize() { return (float)boxSize / 2; };
	Box * getBox(int x, int y) { return &boxs[y+11][x+11]; };
	Box * getStartBox() { return getBox(0, 0); };
};




class Cloud : public Figure {
public:
	void draw();
};

class Clouds : public Figure, GroupFigure {
public:
	Clouds();
	void init();
	void draw();
};


class Yoshi : public MD2Model, Figure, Texture {
public:
	void init();
	void draw();
	void update();
};


class Path {
	std::list<Box *> path;
public:
	Path(){};
	Path(Box * box) : path({ box }) {};
	Box * getCurrentBox() { return path.back(); }
	void addBox(Box * box) { path.push_back(box); }
};

enum class Directions { N, NE, E, SE, S, SW, W, NW };

class Game {
	private:
		Board board;
		Yoshi yoshi;
		std::list<Figure *> decorations;
		Path path;
	public: 
		Game();
		void init(); //loads figure texture
		void draw();
		void update();
		Box * next(Directions direction);
};
#endif
