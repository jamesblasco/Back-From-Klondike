#include "Utils.h"

void glPrint(int x, int y, int z, char *string){
	
	glRasterPos2f(x, y); //set the position of the text in the window using the x, y and z coordinates
	int len = (int)strlen(string); //get the length of the string to display

	//loop to display character by character
	for (int i = 0; i < len; i++) 	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
};
