#ifndef GLUTILS_H
#define GLUTILS_H

#include <stdlib.h>
#include "glut.h"
#include <fstream>
#include <iostream>

#define ESC 27

enum Axis { X, Y, Z };

class Position {
public:
	float x, y, z;
	Position(float x = 0, float y = 0, float z = 0);
	Position operator+(Position c);
	Position operator-(Position c);
	Position operator*(Position c);
	Position operator*(float v);
	int operator==(Position c);
	int operator!=(Position c);
};

extern GLuint KLtexture;

//Callback de gestión del teclado
void OnKeyboardDown(unsigned char key, int x, int y);

GLuint LoadTexture(int width, int height, const char * filename);
void displaytext(GLuint Thetexture);


unsigned int MakeTexture(const char* filename);
void glPrint(int x, int y, int z, char *string);
#endif