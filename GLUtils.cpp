#include "GLUtils.h"
#include "pcxLoader.h"
#include <SOIL/SOIL.h>

Position::Position(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
};

Position Position::operator+(Position c) { 	return Position(c.x + x, c.y+y, c.z+z); }
Position Position::operator-(Position c) {	return Position(x- c.x, y - c.y, z - c.z); }
Position Position::operator*(Position c) { return Position(c.x * x, c.y * y, c.z * z); }
Position Position::operator*(float v) { return Position(x*v, y*v, z*v); }
int Position::operator==(Position c) {	return c.x == x && c.y == y && c.z == z; }
int Position::operator!=(Position c) {	return c.x != x || c.y != y || c.z != z;}
int Position::operator>=(Position c) { return c.x >= x || c.y >= y || c.z >= z; }
int Position::operator>(Position c) { return c.x > x || c.y > y || c.z > z; }
int Position::operator<=(Position c) { return c.x <= x || c.y <= y || c.z <= z; }
int Position::operator<(Position c) { return c.x < x || c.y < y || c.z < z; }
int Position:: isInsideArea(Position pos, Position from, Position to) { return pos >= from && pos <= to; }

Color :: Color(int r, int g, int b, float a){
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a<1 ? a : 1;
}

void glColor(Color color) {	glColor4f(((float)color.r)/255, ((float)color.g) / 255, ((float)color.b) / 255, color.a);}
void glBackgroundColor(Color color) { glClearColor(((float)color.r) / 255, ((float)color.g) / 255, ((float)color.b) / 255, color.a); }


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
GLuint loadImageTexture(const char * filename, int width, int height) {
	
	unsigned char * pixels;

	FILE * file;
	file = fopen(filename, "rb");
	if (file == NULL) return 0;

	pixels = (unsigned char *) malloc(width * height * 3);
	//int size = fseek(file,);
	fread(pixels, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i){
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

GLuint loadPcxTexture(const char* filename) {

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

}GLuint loadSOILTexture(const char* filename, int width, int height) {

	//unsigned char * pixels = SOIL_load_image("test.png", &width, &height, 0, SOIL_LOAD_AUTO);
	//return loadTexture(width, height, pixels);
	return SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA);
}







void glPrint(int x, int y, int z, char *string)
{
	//set the position of the text in the window using the x, y and z coordinates
	glRasterPos3f(x, y, z);
	//get the length of the string to display
	int len = (int)strlen(string);

	//loop to display character by character
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
};