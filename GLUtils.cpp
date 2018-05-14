#include "GLUtils.h"
#include "pcxLoader.h"

Position::Position(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Position Position::operator+(Position c) { 	return Position(c.x + x, c.y+y, c.z+z); }
Position Position::operator-(Position c) {	return Position(x- c.x, y - c.y, z - c.z); }
Position Position::operator*(Position c) { return Position(c.x * x, c.y * y, c.z * z); }
Position Position::operator*(float v) { return Position(x*v, y*v, z*v); }
int Position::operator==(Position c) {	return c.x == x && c.y == y && c.z == z; }
int Position::operator!=(Position c) {	return c.x != x || c.y != y || c.z != z;}

GLuint LoadTexture(int width, int height, const char * filename)
{

	GLuint texture;


	unsigned char * data;

	FILE * file;

	file = fopen(filename, "rb");

	if (file == NULL) return 0;

	data = (unsigned char *)malloc(width * height * 3);
	//int size = fseek(file,);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}


void displaytext(GLuint Thetexture)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, Thetexture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-5.0, -5.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, 5.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(5.0, 5.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(5.0, -5.0, 0.0);

	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
}


/// A function to load a bitmap file and return the texture object for that texture
unsigned int MakeTexture(const char* filename) {

	unsigned int w, h, bpp;
	unsigned char* pixels;

	if (!LoadPcxImage(filename, &pixels, &w, &h, &bpp)) {
		return 0;
	}

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

	unsigned int tex_obj = 0;
	glGenTextures(1, &tex_obj);

	glBindTexture(GL_TEXTURE_2D, tex_obj);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, outfmt, w, h, 0, infmt, GL_UNSIGNED_BYTE, pixels);

	return tex_obj;
}


