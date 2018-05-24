#ifndef FIGURE_H
#define FIGURE_H

#include "../utils/Utils.h"
#include "GLCore.h"
#include "Texture.h"
#include <list>

class Figure {
protected:
	Position pos;
	Position rot;

public:
	Figure();
	Figure(float, float, float);
	
	void getName(char *);
	void setName(char *);
	
	void move(float x, float y, float z, float speed);
	void jump(float distance, float speed);
	void rotate(Axis axis, float speed, float angle=-1);
	void render();

	virtual void draw() = 0;
	void init() {}
};

class GroupFigure {
	protected:
		std::list<Figure*> figures;
};



#endif

