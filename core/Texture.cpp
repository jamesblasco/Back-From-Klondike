#include "Texture.h"
#include "glcore.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include "../textures/pcxLoader.h"
#include <SOIL/SOIL.h>


GLuint loadTexture(int width, int height, unsigned char * pixels) {
	GLuint texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	return texture;
}


/// A function to load a bitmap file and return the texture object for that texture
GLuint loaderImageTexture(const char * filename, int width, int height) {

	unsigned char * pixels;

	FILE * file;
	file = fopen(filename, "rb");
	if (file == NULL) return 0;

	pixels = (unsigned char *)malloc(width * height * 3);
	//int size = fseek(file,);
	fread(pixels, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i) {
		int index = i * 3;
		unsigned char B, R;
		B = pixels[index];
		R = pixels[index + 2];

		pixels[index] = R;
		pixels[index + 2] = B;

	}
	GLuint texture = loadTexture(width, height, pixels);
	free(pixels);

	return texture;
}

GLuint loaderPcxTexture(const char* filename) {

	unsigned int w, h, bpp;
	unsigned char* pixels;

	if (!LoadPcxImage(filename, &pixels, &w, &h, &bpp)) { return 0; }

	GLenum infmt, outfmt;
	switch (bpp) {
	case 3:
		infmt = GL_RGB;
		outfmt = GL_RGB;
		break;
	case 4:
		infmt = GL_RGBA;
		outfmt = GL_RGBA;
		break;
	case 1:
		infmt = outfmt = GL_ALPHA;
		break;
	case 2:
		infmt = outfmt = GL_RGB5_A1;
		break;
	default:
		free(pixels);
		return 0;
	}

	return loadTexture(w, h, pixels);

}GLuint loaderSOILTexture(const char* filename) {

	//unsigned char * pixels = SOIL_load_image("test.png", &width, &height, 0, SOIL_LOAD_AUTO);
	//return loadTexture(width, height, pixels);
	return SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA);
}


void Texture::loadImageTexture(const char * filename, int width, int height) {
	texture = loaderImageTexture(filename, width, height);
}

void Texture::loadPcxTexture(const char* filename) {
	texture = loaderPcxTexture(filename);
}

void Texture::loadSOILTexture(const char* filename) {
	texture = loaderSOILTexture(filename);
}


void glPrint(int x, int y, int z, char *string)
{
	//set the position of the text in the window using the x, y and z coordinates
	glRasterPos2f(x, y);
	//get the length of the string to display
	int len = (int)strlen(string);

	//loop to display character by character
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
};