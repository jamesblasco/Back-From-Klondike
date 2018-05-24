#ifndef TEXTURE_H
#define TEXTURE_H

#include "GLCore.h"

class Texture {
protected:
	GLuint texture;
public:
	void loadImageTexture(const char * filename, int width, int height);
	void loadPcxTexture(const char* filename);
	void loadSOILTexture(const char* filename);
};

void glPrint(int x, int y, int z, char *string);
#endif