//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#ifndef POSITION_H
#define POSITION_H


enum Axis { X, Y, Z };

enum class Dimensions { TWO, THREE };
class Position {
public:
	Dimensions dimensions;
	float x, y, z;
	Position(float x = 0, float y = 0, float z = 0);
	Position(Dimensions dimensions, float x = 0, float y = 0, float z = 0);
	Position operator+(Position c);
	Position operator-(Position c);
	Position operator*(Position c);
	Position operator*(float v);
	int operator==(Position c);
	int operator!=(Position c);
	static int isInsideArea(Position pos, Position from, Position to);
};

#endif