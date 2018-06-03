//
// Created by Jaime Blasco, Clara Landar�bar, Bel�n Garc�a on May 2018.
// 

#ifndef YOSHI_H
#define YOSHI_H

#include "../core/GLFigure.h"
#include "../MD2Model.h"

class Yoshi : public MD2Model, Figure, Texture {
public:
	void init();
	void draw();
	void update();
	void setAnim(unsigned short);
	void changeAnim();
};


#endif