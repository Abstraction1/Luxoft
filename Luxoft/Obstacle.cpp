#include "Obstacle.h"

racing::Obstacle::Obstacle()
{
	symb_ = new char[3];
	symb_[0] = '|';
	symb_[1] = 'X';
	symb_[2] = 'o';

	SetStartCoord(5, 5);
}

void racing::Obstacle::SetStartCoord(const int coordX, const int coordY)
{
	coordX_ = coordX;
	coordY_ = coordY;
}

