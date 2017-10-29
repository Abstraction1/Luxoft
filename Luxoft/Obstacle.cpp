#include "Obstacle.h"

racing::Obstacle::Obstacle()
{
	SetStartCoord(5, 5);
}

int racing::Obstacle::GetX() const
{
	return coordX_;
}

int racing::Obstacle::GetY() const
{
	return coordY_;
}

char racing::Obstacle::GetCentrSymb() const
{
	return centrSymb_;
}

char racing::Obstacle::GetBoardSymb() const
{
	return boardSymb_;
}

char racing::Obstacle::GetWheelsSymb() const
{
	return wheelsSymb_;
}

void racing::Obstacle::SetStartCoord(const int coordX, const int coordY)
{
	coordX_ = coordX;
	coordY_ = coordY;
}

