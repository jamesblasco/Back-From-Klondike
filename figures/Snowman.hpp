//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef SNOWMAN_H
#define SNOWMAN_H

#include "../core/GLFigure.hpp"

//
// Snowman
//
// Example figure
//
class Snowman : public Figure {
public:
	Snowman();
	float snowman_rot = 0;
	void draw();
};

#endif