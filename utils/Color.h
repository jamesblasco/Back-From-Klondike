//
// Created by Jaime Blasco, Clara Landar�bar, Bel�n Garc�a on May 2018.
// 


#ifndef COLOR_H
#define COLOR_H

class Color {
public:
	int r, g, b;
	float a;
	Color(int r = 0, int g = 0, int b = 0, float a = 1);
};

void glColor(Color color);
void glBackgroundColor(Color color);

#endif