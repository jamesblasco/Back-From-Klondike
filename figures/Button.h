//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

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
