#include "Position.h"
#include <math.h>

Position::Position(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
};
Position::Position(Dimensions dimensions, float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = dimensions == Dimensions::TWO ? NAN : z;
};


Position Position::operator+(Position c) { return Position(c.x + x, c.y + y, c.z + z); }
Position Position::operator-(Position c) { return Position(x - c.x, y - c.y, z - c.z); }
Position Position::operator*(Position c) { return Position(c.x * x, c.y * y, c.z * z); }
Position Position::operator*(float v) { return Position(x*v, y*v, z*v); }

int Position::operator==(Position c) { return c.x == x && c.y == y && c.z == z; }
int Position::operator!=(Position c) { return c.x != x || c.y != y || (c.z != NAN ? c.z != z : false); }

int Position::isInsideArea(Position pos, Position from, Position to) {
	return pos.x >= from.x && pos.x <= to.x && pos.y >= from.y && pos.y <= to.y;
}