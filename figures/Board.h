#ifndef BOARD_H
#define  BOARD_H

#include "../core/GLFigure.h"
#include "Box.h"

#define SIZE 23

class Board : public Figure, Texture {
	int boxSize;
public:

	Box boxs[SIZE][SIZE];

	Board();
	void init();
	void draw();
	float getSize() { return boxSize * SIZE; };
	float getBoxSize() { return (float)boxSize; };
	float getHalbSize() { return boxSize * SIZE / 2; };
	float getHalbBoxSize() { return (float)boxSize / 2; };
	Box * getBox(int x, int y) { return &boxs[y + 11][x + 11]; };
	Box * getStartBox() { return getBox(0, 0); };
	void reset();

};



#endif

