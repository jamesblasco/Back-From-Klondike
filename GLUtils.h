#ifndef GLUTILS_H
#define GLUTILS_H

#include <stdlib.h>

#include <GL/glut.h>

#include <fstream>
#include <iostream>
#include <math.h>

#define ESC 27
#define PI 3.14159265

enum Axis { X, Y, Z };
enum Dimensions { TWO,  THREE };

class Position {
	public:
		float x, y, z;
		Position(float x = 0, float y = 0, float z = 0);
		Position(Dimensions dimenisons, float x = 0, float y = 0, float z = 0);
		Position operator+(Position c);
		Position operator-(Position c);
		Position operator*(Position c);
		Position operator*(float v);
		int operator==(Position c);
		int operator!=(Position c);
		static int isInsideArea(Position pos, Position from, Position to);
};

class Color {
public:
	int r, g, b;
	float a;
	Color(int r = 0, int g = 0, int b = 0, float a = 1);
};

void glColor(Color color);
void glBackgroundColor(Color color);

enum class Buttons { 
	NONE, 
	LEFT = GLUT_LEFT_BUTTON,
	CENTER = GLUT_MIDDLE_BUTTON, 
	RIGHT  = GLUT_RIGHT_BUTTON,
};
enum class Arrows {
	NONE,
	LEFT = GLUT_KEY_LEFT,
	RIGHT = GLUT_KEY_RIGHT,
	UP = GLUT_KEY_UP,
	DOWN = GLUT_KEY_DOWN,
};
class Mouse {
public:
	Position pos = Position();
	Buttons button = Buttons::NONE;
	Arrows arrows = Arrows::NONE;
	Position update(int x, int y) {
		Position newer = Position(x, y);
		Position diff = newer - pos;
		pos = newer;
		return diff;
	}
};

class Perspective {
public:
	float zoom = 400;
	Position pos = Position(0,0, 0); //
	Position rot = Position(10, 0, 0);

	void move(Position variation) {
		pos.x += (float) 0.5f * ( variation.x * cos(rot.y*PI / 180) - variation.y * sin(rot.y*PI / 180));
	 	pos.z += (float) 0.5f * (variation.y * cos(rot.y*PI / 180) + variation.x * sin(rot.y*PI / 180));
	}
	void rotate(Position variation) {
		
		rot.y += (float) 0.5f * variation.x  ;
		rot.x += (float) 0.5f * variation.y;
		//rot.z += (float) 0.5f * variation.y * sin(rot.y*PI / 180);
		std::cout << "rot y:" << rot.y << " rot x:" << rot.x << "  rot z:" << rot.z << "\n";
	
	}
	void draw(){
		glTranslatef(0, 0, -zoom);
		
		glRotatef(rot.x, 1, 0, 0);
		glRotatef(rot.z, 0, 0, 1);
		glRotatef(rot.y, 0, 1, 0);
		
		glTranslatef(0, 0, pos.z);
		glTranslatef(0, pos.y, 0);
		glTranslatef(pos.x, 0, 0);

	}
};



GLuint loadImageTexture(const char * filename, int width, int height);
GLuint loadPcxTexture(const char* filename);
GLuint loadSOILTexture(const char* filename, int width, int height);


void glPrint(int x, int y, int z, char *string);
#endif