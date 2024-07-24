#pragma once
#include "Graphics.h"
#include "Dude.h"
class Poo
{
private:
	int x;
	int y;
	void ClampToScreen();
public:
	static constexpr int height = 24;
	static constexpr int width = 24;
	bool incX;
	bool incY;

public:
	bool eaten;
	Poo();
	Poo(int x, int y, bool incX, bool incY);
	int GetX();
	int GetY();
	void Update();
	void Consumtion(Dude dude);
};

