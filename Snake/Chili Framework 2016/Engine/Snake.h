#pragma once
#include "Location.h"
#include "Board.h"
#include <vector>
#include "Colors.h"

class Snake
{
private:
	class Segment
	{
	private:
		Location location;
		Color color;
	public:
		Location GetLocation();
		Segment(Location location, Color color);
		void Draw(const Board& board) const;
		Color GetColor()
		{
			return color;
		}
		void ChangeColor(Color color)
		{
			this->color = color;
		}
	};

	std::vector<Segment*> segments;
	int length;
	Location direction;

public:
	Snake(Location location, int length);
	Location MoveNext();
	void MoveUp()
	{
		Location newDirection = Location(0, -1);
		if(newDirection.GetX() != direction.GetX())
			direction = newDirection;
	}

	void MoveDown()
	{
		Location newDirection = Location(0, 1);
		if (newDirection.GetX() != direction.GetX())
			direction = newDirection;
	}

	void MoveLeft()
	{
		Location newDirection = Location(-1, 0);
		if (newDirection.GetY() != direction.GetY())
			direction = newDirection;
	}

	void MoveRight()
	{
		Location newDirection = Location(1, 0);
		if (newDirection.GetY() != direction.GetY())
			direction = newDirection;
	}

	void Draw(Board& board) const;
};

