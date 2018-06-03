//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#ifndef POSITION2_H
#define POSITION2_H

#include "Position.h"

class Position2D : public Position {
public:
	Position2D(float x = 0, float y = 0) : Position(Dimensions::TWO, x, y) {};
	Position2D(const Position& a) : Position(a) { }
};

#endif