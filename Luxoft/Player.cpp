#include "Player.h"

racing::Player::Player()
{
	SetStartCoord(5, 15);
}

int racing::Player::GetX() const
{
	return playerCoordX_;
}

int racing::Player::GetY() const
{
	return playerCoordY_;
}

char racing::Player::GetPlayerCentrSymb() const
{
	return playerCentrSymb;
}

char racing::Player::GetPlayerBoardSymb() const
{
	return playerBoardSymb;
}

char racing::Player::GetPlayerWheelsSymb() const
{
	return playerWheelsSymb;
}

void racing::Player::SetStartCoord(const int playerCoordX, const int playerCoordY)
{
	playerCoordX_ = playerCoordX;
	playerCoordY_ = playerCoordY;
}

