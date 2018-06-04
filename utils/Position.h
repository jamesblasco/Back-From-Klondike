//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#ifndef POSITION_H
#define POSITION_H


enum Axis { X, Y, Z }; // 3D AXIS
enum class Dimensions { TWO, THREE }; // TWO or THREE dimensions vector


//
// Position
//
// Util class for 3D vector, allows operations and comparisons 
//
class Position {
public:
	Dimensions dimensions; // 3D or 2D dimensiosn
	float x, y, z;
	Position(float x = 0, float y = 0, float z = 0);
	Position(Dimensions dimensions, float x = 0, float y = 0, float z = 0);
	Position operator+(Position c);
	Position operator-(Position c);
	Position operator*(Position c);
	Position operator*(float v);
	int operator==(Position c);
	int operator!=(Position c);
	
	//Check if 3D array is inside a cube
	static int isInsideArea(Position pos, Position from, Position to);
};


//
// Position2D
//
// Easy way of creating 2D Vector
//
class Position2D : public Position {
public:
	Position2D(float x = 0, float y = 0) : Position(Dimensions::TWO, x, y) {};
	Position2D(const Position& a) : Position(a) { }
};

#endif