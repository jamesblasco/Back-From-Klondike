#ifndef LOGO_H
#define  LOGO_H

#include "../core/GLFigure.h"

//
// Logo
//
// Extends: Figure(is drawn with opengl)
// Logo 
//
class Logo : public Figure {
	Texture texture;
public:
	void init();  //Init textures
	void draw(); // Draw board and boxes with openGL
};

#endif //LOGO_H

