#ifndef SNOWMAN_H
#define SNOWMAN_H

#include "../core/GLFigure.h"

class Snowman : public Figure {
public:
	Snowman();
	float snowman_rot = 0;
	void draw();
};

#endif