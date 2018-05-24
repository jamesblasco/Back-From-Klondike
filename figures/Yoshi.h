#ifndef YOSHI_H
#define YOSHI_H

#include "../core/GLFigure.h"
#include "../MD2Model.h"

class Yoshi : public MD2Model, Figure, Texture {
public:
	void init();
	void draw();
	void update();
};


#endif