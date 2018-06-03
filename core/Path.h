//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#ifndef PATH_H
#define PATH_H

#include "../figures/Box.h"
#include <list>

//
// Path
//
// List of boxes indicating the path that yoshi has already traveled
//
class Path {
	std::list<Box *> path;
public:
	Path(Box * box) : path({ box }) {}; // Init path with starter box
	Box * getCurrentBox() { return path.back(); } // Get the box where yoshi is it located
	void addBox(Box * box) { path.push_back(box); }  // Add a new box to the path
	void clear(); // Remove path and begin in the starter box
};

#endif

