#include "Location.h"

Location::Location(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Location::GetX()
{
	return x;
}

int Location::GetY()
{
	return y;
}

bool Location::operator==(const Location& obj) const
{
	return x == obj.x && y == obj.y;
}

bool Location::operator!=(const Location& obj) const
{
	return x != obj.x || y != obj.y;
}

Location Location::operator+(const Location& obj) const
{
	return Location(x + obj.x, y + obj.y);
}