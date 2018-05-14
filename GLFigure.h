#ifndef FIGURE_H
#define FIGURE_H

#include "GLUtils.h"

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
	
	virtual void draw() = 0;
};

class Snowman : public Figure {
	public:
		Snowman();
		float snowman_rot = 0;
		void draw();
};

#endif

