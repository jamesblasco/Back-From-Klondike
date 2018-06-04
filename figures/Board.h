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
	Box boxs[SIZE][SIZE]; //Matrix containing each box
public:
	
	Board(); //Init board with default values and create each box
	void init();  //Init textures
	void draw(); // Draw board and boxes with openGL
	void reset(); // Set default values again, clear searcher resolution algorithm state in boxes

	float getSize() { return boxSize * SIZE; }; // Get Board Size (Height == Width)
	float getHalbSize() { return boxSize * SIZE / 2; }; // Get Board Size / 2 - Used for get center in board

	float getBoxSize() { return (float)boxSize; }; // Get Box Size (Height == Width)
	float getHalbBoxSize() { return (float)boxSize / 2; }; // Get Box Size / 2 - Used for get center in box
	
	Box * getBox(int x, int y) { return &boxs[y + 11][x + 11]; }; // Get Box from relative position
	Box * getStartBox() { return getBox(0, 0); }; // Get Start Box 
	

};



#endif

