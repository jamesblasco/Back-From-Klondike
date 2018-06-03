//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 


#ifndef GAME_H
#define GAME_H


#include "GLFigure.h"
#include "Path.h"
#include "../figures/Board.h"
#include "../figures/Box.h"
#include "../figures/Yoshi.h"

// User Modes  
//	 AUTO: Show the solution
//   USER: User can play 
enum class GameMode { AUTO, USER };

// GAME  
//	Main class, all the mechanism of the game is controlled from here,
//  drawing of figures, game modes, animations...
// 
static class Game {
	private:
		static Board board; // Texture and all squares
		static Yoshi yoshi; // Main figure
		static std::list<Figure *> decorations; // Other figures
		static Path path; // Path of passed boxes
		static	std::list<Box *> solution; //Solution path
		static GameMode mode; // User Modes (AUTO, USER)

		static void buildSolution(Box* goal); // Given a box, build path solution from their parents
		
	public: 
		static void init(); // Loads Figure Textures
		static void reset(); // Loads default values
		static void update(); // Update Yoshi anim
		static void changeMode(GameMode mode); // Change game mode

		static void draw(); // Draw all figures in the game
		
		static void solve(); // Get path solution

		static Box * next(Directions direction);  // GET next box in USER MODE
		static Box * nextStepInSolution(); // GET next box in AUTO MODE

		static bool isAutoMode() { return mode == GameMode::AUTO; }; // Check if it is in AUTO MODE
		static bool isUserMode() { return mode == GameMode::USER; }; // Check if it is in USER MODE
		static bool hasSolution() { return solution.size() > 0; }; // Check if it has solution

		Yoshi * getYoshi() { return &yoshi; }; // Get Yoshi

} game;
#endif
