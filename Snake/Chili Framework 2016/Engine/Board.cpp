#include "Board.h"

Board::Board(Graphics& gfx, int width, int height, int dimension)
	:
	gfx(gfx)
{
	this->width = width;
	this->height = height;
	this->dimension = dimension;
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

void Board::Draw(Location location, Color color) const
{
	gfx.DrawRectDim(location.GetX() * dimension, location.GetY() * dimension, dimension, color);
}
