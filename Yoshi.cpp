#include "Yoshi.h"
#include "GLUtils.h"
#include "FrameTimer.h"

void Yoshi :: init () {
	Load("tris.md2");
	// write memory usage
	std::cout << "memory usage " << (GetDataSize() / 1024.0f) << "kb\n";
	//texture = MakeTexture("yoshi.pcx");
}

void Yoshi::draw() {
	//glBindTexture(GL_TEXTURE_2D, texture);
	Render();
}

void Yoshi::update() {
	Update(FrameTime());
}