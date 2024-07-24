#include "Dude.h"

void Dude::ClampToScreen()
{
	if (x + width >= Graphics::ScreenWidth)
		x = Graphics::ScreenWidth - width - 1;
	if (x < 0)
		x = 0;

	if (y + height >= Graphics::ScreenHeight)
		y = Graphics::ScreenHeight - height - 1;
	if (y < 0)
		y = 0;
}

Dude::Dude()
{
}

Dude::Dude(int x, int y)
{
	this->x = x;
	this->y = y;
	ClampToScreen();
}

void Dude::Update(int x, int y)
{
	this->x = x;
	this->y = y;
	ClampToScreen();
}

int Dude::GetX()
{
	return x;
}

int Dude::GetY()
{
	return y;
}
