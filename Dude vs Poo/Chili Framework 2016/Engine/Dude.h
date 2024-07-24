#pragma once
#include "Graphics.h"
class Dude
{
private:
	int x; 
	int y;
	void ClampToScreen();
public:
	static constexpr int height = 20;
	static constexpr int width = 20;
	Dude();
	Dude(int x, int y);
	void Update(int x, int y);
	int GetX();
	int GetY();
};

