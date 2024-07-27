#pragma once
class Location
{
private:
	int x;
	int y;

public:
	Location(int x, int y);
	int GetX();
	int GetY();
	bool operator==(const Location& obj) const;
	bool operator!=(const Location& obj) const;
	Location operator+(const Location& obj) const;
};

