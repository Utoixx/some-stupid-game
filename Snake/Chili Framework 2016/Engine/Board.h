#pragma once
#include "Location.h"
#include "Colors.h"
#include "Graphics.h"

class Board
{
private:
	Graphics& gfx;
	int width;
	int height;
	int dimension; //size 
public:
	Board(Graphics& gfx, int width, int height, int dimension);
	int GetWidth() const;
	int GetHeight() const;
	void Draw(Location location, Color color) const;
};

