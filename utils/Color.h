//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#ifndef COLOR_H
#define COLOR_H

//
// Color
//
// Util class for rgba colors 
//
class Color {
public:
	int r, g, b;
	float a;
	Color(int r = 0, int g = 0, int b = 0, float a = 1);
};


// Extend glColor opengl function with custom Color class
void glColor(Color color);
// Extend glClearColor opengl function with custom Color class - Used for background screen color
void glBackgroundColor(Color color);

#endif