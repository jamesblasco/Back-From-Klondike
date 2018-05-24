#ifndef BUTTON_H
#define BUTTON_H

#include "../core/GLFigure.h"
#include "../core/Window.h"

class Button : public Figure {
public:
	enum status { NONE, HOVER, PRESSED };
	void draw();
	void updateStatus(Window* window);
};


#endif
