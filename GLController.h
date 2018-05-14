#ifndef GLCONTROLLER_H
#define GLCONTROLLER_H

#include <iostream>
#include "glut.h"
#include "GLUtils.h"

void onMouse(int button, int state, int x, int y);
void onMotion(int x, int y);
void onResize(int w, int h);
void onKeyboardDown(unsigned char key, int x, int y);
void onDisplay();
void onIdle();
void init();

#endif
