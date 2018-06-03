//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef CLOUDS_H
#define CLOUDS_H

#include "../core/GLFigure.h"

class Clouds : public Figure, GroupFigure {
public:
	Clouds();
	void init();
	void draw();
};

#endif