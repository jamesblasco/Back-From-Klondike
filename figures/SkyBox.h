#ifndef SKYBOX_H
#define  SKYBOX_H

#include "../core/GLFigure.h"
//
// Skybox
//
// Extends: Figure(is drawn with opengl)
// Background
//

enum class SKY {FRONT, RIGHT, LEFT, BACK, UP, DOWN};
class SkyBox : public Figure {
	Texture textures[6];

public:
	void init();  //Init textures
	void draw(); // Draw board and boxes with openGL
};

#endif //SKYBOX_H

