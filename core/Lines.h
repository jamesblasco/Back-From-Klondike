#ifndef LINES_H
#define LINES_H

#include "GLFigure.h"
#include "Window.h"

class Lines : public Figure {
public:
	enum status { NONE, HOVER, PRESSED };
	void draw();
	void updateStatus(Window* window);
};

#endif