//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef FIGURE_H
#define FIGURE_H

#include "../utils/Utils.h"
#include "GLCore.h"
#include "Texture.h"
#include <list>


//
// Figure
//
// Basic class for OpenGl Figures.
// Add position and rotation properties and allows animations as jump, rotate and move
//
class Figure {
protected:
	Position pos; // 3D Vector for position
	Position rot; // 3D Vector for rotation
	float jumpPos; // Current AXIS-Y Position in jumping

public:
	Figure(); // Init Figure
	Figure(float, float, float);  // Init Figure with position

	void move(float x, float y, float z, float speed);   // Changes figure position in an animated way
	void jump(float distance, float speed); // Jump Animation
	void rotate(Axis axis, float speed, float angle=-1); // Allow rotation in three AXIS(X, Y, Z), if not angle inserted infinite rotation 
	
	virtual void draw() = 0; // Custom function for each figure that allows you to draw a figure with openGL
	void render(); // Calls draw figure and add animations
		
};

//
// GroupFigure
//
class GroupFigure {
	protected:
		std::list<Figure*> figures;
};





#endif

