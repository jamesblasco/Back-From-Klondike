#include "Color.h"
#include "../core/GLCore.h"

Color::Color(int r, int g, int b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a<1 ? a : 1;
}

void glColor(Color color) { glColor4f(((float)color.r) / 255, ((float)color.g) / 255, ((float)color.b) / 255, color.a); }
void glBackgroundColor(Color color) { glClearColor(((float)color.r) / 255, ((float)color.g) / 255, ((float)color.b) / 255, color.a); }

