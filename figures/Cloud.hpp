//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef CLOUD_H
#define CLOUD_H

#include "../core/GLFigure.hpp"

//
// Cloud
//
// Decoration figure
//
class Cloud : public Figure {
	float relative;
public:
	Cloud() {};
	Cloud(float rel) { relative = rel; };
	void draw();
	float getRel() { return relative; };
};


#endif