//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef YOSHI_H
#define YOSHI_H

#include "../core/GLFigure.h"
#include "../include/MD2Model.h"

//
// Yoshi
//
// Main figure that allows specialized animations
// Extends: Figure(is drawn with opengl), 
//          MD2Model(Open Source library for advanced openGL figures)
//
class Yoshi : public MD2Model, public Figure {
	Texture texture; // Texture (textures are used to draw it)
public:
	void init(); // Init textures
	void draw(); // Draw textures
	void update(); // Update animations
	void setAnim(unsigned short); // Set animation
	void changeAnim(); // Change animation between defualts
};


#endif