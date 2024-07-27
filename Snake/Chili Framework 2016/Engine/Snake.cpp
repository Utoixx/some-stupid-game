#include "Snake.h"

inline Location Snake::Segment::GetLocation()
{
	return location;
}

inline Snake::Segment::Segment(Location location, Color color)
	:
	location(location)
{
	this->color = color;
}

inline void Snake::Segment::Draw(const Board& board) const
{
	board.Draw(location, color);
}

Snake::Snake(Location location, int length)
	:
	direction(1, 0)
{
	for (int i = length - 1; i > 0; --i)
	{
		Location tailLoc(location.GetX() - i, location.GetY());
		Segment* tail = new Segment(tailLoc, Colors::Green);
		segments.push_back(tail);
	}
	Segment* head = new Segment(location, Colors::Red); //Init head of snake
	segments.push_back(head);
	this->length = length;
}

Location Snake::MoveNext()
{
	Segment* tail = segments.front();
	segments.erase(segments.begin());
	Segment* head = segments.back();
	head->ChangeColor(Colors::Green); //Change head to segment
	Location newHeadLoc = head->GetLocation() + direction;
	Segment* newHead = new Segment(newHeadLoc, Colors::Red);
	segments.push_back(newHead);

	return newHeadLoc;
}

void Snake::Draw(Board& board) const
{
	for (auto segment : segments)
	{
		board.Draw(segment->GetLocation(), segment->GetColor());
	}
}
