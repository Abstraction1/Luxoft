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
	return coordY_;
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
	return wheelsSymb;
}

void racing::Player::SetStartCoord(const int playerCoordX, const int playerCoordY)
{
	playerCoordX_ = playerCoordX;
	coordY_ = playerCoordY;
}

