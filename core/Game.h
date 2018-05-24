#ifndef GAME_H
#define GAME_H


#include "GLFigure.h"
#include "Path.h"
#include "../figures/Board.h"
#include "../figures/Box.h"
#include "../figures/Yoshi.h"



enum class Directions { N, NE, E, SE, S, SW, W, NW };

static class Game {
	private:
		static Board board;
		static Yoshi yoshi;
		static std::list<Figure *> decorations;
		static Path path;
	public: 
		static void init(); //loads figure texture
		static void draw();
		static void update();
		static Box * next(Directions direction);
} game;
#endif
