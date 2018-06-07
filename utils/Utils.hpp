//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef UTILS_H
#define UTILS_H


#define ESC 27
#define PI 3.14159265

#include "Color.hpp"
#include "Position.hpp"
#include "Position2D.hpp"
#include "../core/GLCore.hpp"

// Print text on screen with opengl
void glPrint(int x, int y, int z, char *string);

#endif