#include "Poo.h"

void Poo::ClampToScreen()
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

Poo::Poo()
{

}

Poo::Poo(int x, int y, bool incX, bool incY)
{
	this->x = x;
	this->y = y;
	this->incX = incX;
	this->incY = incY;
	this->eaten = false;
	ClampToScreen();
}

int Poo::GetX()
{
	return x;
}

int Poo::GetY()
{
	return y;
}

void Poo::Update()
{
	if (incX)
		x++;
	else
		x--;
	if (incY)
		y++;
	else
		y--;

	if (x + 24 == Graphics::ScreenWidth - 1)
		incX = false;
	if (x == 0)
		incX = true;
	if (y + 24 == Graphics::ScreenHeight - 1)
		incY = false;
	if (y == 0)
		incY = true;
}

void Poo::Consumtion(Dude dude)
{
	if (dude.GetX() >= (x - width / 2) &&
		dude.GetX() <= (x + width / 2) &&
		dude.GetY() >= (y - height / 2) &&
		dude.GetY() <= (y + height / 2)
		)
	{
		eaten = true;
	}
}
