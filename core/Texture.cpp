//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#include "Texture.h"
#include "glcore.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include "../include/pcxLoader.h"
#include <SOIL/SOIL.h>


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>

//Load texture from given pixels
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


// Load a bitmap file and return the texture object 
GLuint loaderImageTexture(const char * filename, int width, int height) {
		unsigned char * pixels;

	FILE * file;
	file = fopen(filename, "rb");
	if (file == NULL) return 0;

	pixels = (unsigned char *)malloc(width * height * 3);
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

// Load a pcx file and return the texture object 
GLuint loaderPcxTexture(const char* filename) {
	unsigned int w, h, bpp;
	unsigned char* pixels;

	if (!LoadPcxImage(filename, &pixels, &w, &h, &bpp)) { return 0; }

	GLenum infmt, outfmt;
	switch (bpp) {
		case 3:	infmt = GL_RGB;  outfmt = GL_RGB; break;
		case 4:	infmt = GL_RGBA; outfmt = GL_RGBA;	break;
		case 1: infmt = outfmt = GL_ALPHA;   		break;
		case 2:	infmt = outfmt = GL_RGB5_A1;		break;
		default:	free(pixels);		return 0;
	}

	return loadTexture(w, h, pixels);
}

// Load a PNG file and return the texture object 
GLuint loaderSOILTexture(const char* filename) {
	return SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA);
}


static void reverse(void* x, const int n)
{
	int k; char* ch = (char*)x;
	for (k = 0; k<n / 2; k++)	{
		char tmp = ch[k];
		ch[k] = ch[n - 1 - k];
		ch[n - 1 - k] = tmp;
	}
}
// Print error
void fatal(const char* format, ...) {	std::cout << format; }

// Load a BMP file and return the texture object 
GLuint loaderTexBMP(const char* file)
{
	unsigned int   texture;    /* Texture name */
	FILE*          f;          /* File pointer */
	unsigned short magic;      /* Image magic */
	unsigned int   dx, dy, size; /* Image dimensions */
	unsigned short nbp, bpp;    /* Planes and bits per pixel */
	unsigned char* image;      /* Image data */
	unsigned int   k;          /* Counter */

							   /*  Open file */
	f = fopen(file, "rb");
	if (!f) fatal("Cannot open file %s\n", file);
	/*  Check image magic */
	if (fread(&magic, 2, 1, f) != 1) fatal("Cannot read magic from %s\n", file);
	if (magic != 0x4D42 && magic != 0x424D) fatal("Image magic not BMP in %s\n", file);
	/*  Seek to and read header */
	if (fseek(f, 16, SEEK_CUR) || fread(&dx, 4, 1, f) != 1 || fread(&dy, 4, 1, f) != 1 ||
		fread(&nbp, 2, 1, f) != 1 || fread(&bpp, 2, 1, f) != 1 || fread(&k, 4, 1, f) != 1)
		fatal("Cannot read header from %s\n", file);
	/*  Reverse bytes on big endian hardware (detected by backwards magic) */
	if (magic == 0x424D) {
		reverse(&dx, 4);
		reverse(&dy, 4);
		reverse(&nbp, 2);
		reverse(&bpp, 2);
		reverse(&k, 4);
	}
	/*  Check image parameters */
	if (dx<1 || dx>65536) fatal("%s image width out of range: %d\n", file, dx);
	if (dy<1 || dy>65536) fatal("%s image height out of range: %d\n", file, dy);
	if (nbp != 1)  fatal("%s bit planes is not 1: %d\n", file, nbp);
	if (bpp != 24) fatal("%s bits per pixel is not 24: %d\n", file, bpp);
	if (k != 0)    fatal("%s compressed files not supported\n", file);
#ifndef GL_VERSION_2_0
	/*  OpenGL 2.0 lifts the restriction that texture size must be a power of two */
	for (k = 1; k<dx; k *= 2);
	if (k != dx) fatal("%s image width not a power of two: %d\n", file, dx);
	for (k = 1; k<dy; k *= 2);
	if (k != dy) fatal("%s image height not a power of two: %d\n", file, dy);
#endif

	/*  Allocate image memory */
	size = 3 * dx*dy;
	image = (unsigned char*)malloc(size);
	if (!image) fatal("Cannot allocate %d bytes of memory for image %s\n", size, file);
	/*  Seek to and read image */
	if (fseek(f, 20, SEEK_CUR) || fread(image, size, 1, f) != 1)
		fatal("Error reading data from image %s\n", file);
	fclose(f);
	/*  Reverse colors (BGR -> RGB) */
	for (k = 0; k<size; k += 3) {
		unsigned char temp = image[k];
		image[k] = image[k + 2];
		image[k + 2] = temp;
	}

	/*  Generate 2D texture */
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	/*  Copy image */
	glTexImage2D(GL_TEXTURE_2D, 0, 3, dx, dy, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	if (glGetError()) fatal("Error in glTexImage2D %s %dx%d\n", file, dx, dy);
	/*  Scale linearly when image size doesn't match */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	/*  Free image memory */
	free(image);
	/*  Return texture name */
	return texture;
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

void Texture::loadTexBMP(const char* filename) {
	texture = loaderTexBMP(filename);
}
