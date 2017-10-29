#include "Player.h"

racing::Player::Player()
{
	centrSymb_ = 'X';
	boardSymb_ = '|';
	wheelsSymb_ = 'o';
	SetStartCoord(5, 15);
}

int racing::Player::GetX() const
{
	return coordX_;
}

int racing::Player::GetY() const
{
	return coordY_;
}

char racing::Player::GetCentrSymb() const
{
	return centrSymb_;
}

char racing::Player::GetBoardSymb() const
{
	return boardSymb_;
}

char racing::Player::GetWheelsSymb() const
{
	return wheelsSymb_;
}

void racing::Player::SetStartCoord(const int playerX, const int playerY)
{
	coordX_ = playerX;
	coordY_ = playerY;
}

