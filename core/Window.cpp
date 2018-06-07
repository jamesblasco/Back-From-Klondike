//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#include "Window.hpp"
#include "GLCore.hpp"

int Window::width = 0;
int Window::height = 0;

//Calls when windos is resized
void Window::onResize(int w, int h) {
	if (w == 0)	h = 1; // prevent divide by 0 error when minimised
	window.updateSize();
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 1, 200000);
	//glOrtho(0.0f, w, h, 0.0f, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}