#pragma once

namespace racing
{
	class Player
	{
	private:
		int playerCoordX_;
		int playerCoordY_;
		char playerCentrSymb = 'X';
		char playerBoardSymb = '|';
		char playerWheelsSymb = 'o';
	public:
		Player();
		int GetX() const;
		int GetY() const;
		char GetPlayerCentrSymb() const;
		char GetPlayerBoardSymb() const;
		char GetPlayerWheelsSymb() const;
		void SetStartCoord(const int playerCoordX, const int playerCoordY);
	};
}