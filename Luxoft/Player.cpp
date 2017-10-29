#include "Player.h"

racing::Player::Player()
{
	symb_ = new char[3];
	symb_[0] = 'X';
	symb_[1] = '|';
	symb_[2] = 'o';

	SetStartCoord(18, 5);
}

void racing::Player::SetStartCoord(const int playerX, const int playerY)
{
	coordX_ = playerX;
	coordY_ = playerY;
}


racing::Player& racing::Player::operator--()
{
	coordY_--;
	return *this;
}

racing::Player & racing::Player::operator++()
{
	coordY_++;
	return *this;
}

racing::Player::~Player()
{
	delete[] symb_;
}


