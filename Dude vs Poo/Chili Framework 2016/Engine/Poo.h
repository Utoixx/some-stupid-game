#pragma once
#include "Graphics.h"
#include "Dude.h"
class Poo
{
private:
	int x;
	int y;
	bool incX;
	bool incY;
	void ClampToScreen();
	bool eaten;
	static constexpr int height = 24;
	static constexpr int width = 24;
	bool initialed = false;
public:
	static int GetHeight();
	static int GetWidth();
	void Init(int x, int y, bool incX, bool incY);
	void Update();
	bool IsEaten() const;
	void Consumtion(const Dude& dude);
	void Draw(Graphics& gfx) const;
	bool IsInitialed();
};

