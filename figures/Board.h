#ifndef BOARD_H
#define  BOARD_H

#include "../core/GLFigure.h"
#include "Box.h"

#define SIZE 23 // Number of boxes in a row or column

//
// Board
//
// Extends: Figure(is drawn with opengl), Texture (textures are used to draw it)
// He is responsible for drawing the board and managing the boxes inside the board
//
class Board : public Figure, Texture {
	int boxSize; // Height and width of boxes
public:

	Box boxs[SIZE][SIZE]; //Matrix containing each box

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

