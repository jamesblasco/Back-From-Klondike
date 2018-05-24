#ifndef PATH_H
#define PATH_H

#include "../figures/Box.h"
#include <list>


class Path {
	std::list<Box *> path;
public:
	Path() {};
	Path(Box * box) : path({ box }) {};
	Box * getCurrentBox() { return path.back(); }
	void addBox(Box * box) { path.push_back(box); }
};

#endif

