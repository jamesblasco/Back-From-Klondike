//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef TEXTURE_H
#define TEXTURE_H

#include "GLCore.hpp"

//
// Texture
//
// Allows to init, save and display textures
//
class Texture {
protected:
	GLuint texture; //Texture
public:
	void loadImageTexture(const char * filename, int width, int height);  //Load Bitmap texture
	void loadPcxTexture(const char* filename); //Load PCX texture
	void loadSOILTexture(const char* filename);  //Load PNG and other image format texture
	void loadTexBMP(const char* filename);
	GLuint get() { return texture; };
};


#endif