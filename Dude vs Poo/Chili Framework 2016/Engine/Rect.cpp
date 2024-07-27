#include "Rect.h"
#include "Graphics.h"
#include "Colors.h"
#include <random>

Rect::Rect(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	ClampToScreen();
}

void Rect::ClampToScreen()
{
	if (x >= Graphics::ScreenWidth)
		x = Graphics::ScreenWidth - 1;
	if (x + width >= Graphics::ScreenWidth)
		width = Graphics::ScreenWidth - x - 1;

	if (x < 0)
	{
		width = width + x;
		x = 0;
	}

	if (y >= Graphics::ScreenHeight)
		y = Graphics::ScreenHeight - 1;
	if (y + height >= Graphics::ScreenHeight)
		height = Graphics::ScreenHeight - y - 1;

	if (y < 0)
	{
		height = height + y;
		y = 0;
	}
}

void Rect::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	ClampToScreen();
}

int Rect::GetWidth()
{
	return width;
}

int Rect::GetHeight()
{
	return height;
}

int Rect::GetX()
{
	return x;
}

int Rect::GetY()
{
	return y;
}

void Rect::ChangeSizeUp(int value)
{
	y-= value;
	height+= value;
	ClampToScreen();
}

void Rect::ChangeSizeDown(int value)
{
	++height;
	ClampToScreen();
}

void Rect::ChangeSizeLeft(int value)
{
	x-= value;
	width+= value;
	ClampToScreen();
}

void Rect::ChangeSizeRight(int value)
{
	width+= value;
	ClampToScreen();
}

bool Rect::Colliding(Dude& dude)
{
	if (dude.GetX() >= x && dude.GetX() <= x + width &&
		dude.GetY() >= y && dude.GetY() <= y + height)
	{
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distrX(width, Graphics::ScreenWidth - width - 1); // define the range
		std::uniform_int_distribution<> distrY(height, Graphics::ScreenHeight - height - 1); // define the range
		x = distrX(gen);
		y = distrY(gen);
		this->ClampToScreen();
		return true;
	}
	return false;
}

void Rect::Draw(Graphics& gfx, Color& color) const
{
	for (int j = y; j <= y + height; ++j)
		for (int i = x; i <= x + width; ++i)
			gfx.PutPixel(i, j, color);
}
