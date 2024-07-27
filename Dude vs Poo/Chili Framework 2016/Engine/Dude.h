#pragma once
#include "Graphics.h"
class Dude
{
private:
	int x; 
	int y;
	void ClampToScreen();
	static constexpr int height = 20;
	static constexpr int width = 20;
public:
	static int GetWidth();
	static int GetHeight();
	Dude(int x, int y);
	void Update(int x, int y);
	int GetX() const;
	int GetY() const;
	void Draw(Graphics& gfx) const;
};

