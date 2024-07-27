#pragma once
#include "Graphics.h"
#include "Dude.h"

class Rect
{
private:
	int x;
	int y;
	int width;
	int height;
public:
	Rect(int x, int y, int width, int height);
	void ClampToScreen();
	void SetPosition(int x, int y);
	int GetWidth();
	int GetHeight();
	int GetX();
	int GetY();
	void Draw(Graphics& gfx, Color& color) const;
	void ChangeSizeUp(int value);
	void ChangeSizeDown(int value);
	void ChangeSizeLeft(int value);
	void ChangeSizeRight(int value);
	bool Colliding(Dude& dude);
};

