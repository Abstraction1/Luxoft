#include "Obstacle.h"

char racing::Obstacle::GetObstCentrSymb() const
{
	return obstCentrSymb_;
}

char racing::Obstacle::GetObstBoardSymb() const
{
	return obstBoardSymb_;
}

char racing::Obstacle::GetObstWheelsSymb() const
{
	return obstWheelsSymb_;
}

void racing::Obstacle::SetObstStartCoord(const int coordX, const int coordY)
{
	obstCoordX_ = coordX;
	obstCoordX_ = coordY;;
}
