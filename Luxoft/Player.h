#pragma once

namespace racing
{
	class Player
	{
	public:
		Player();
		int GetX() const;
		int GetY() const;
		char GetPlayerCentrSymb() const;
		char GetPlayerBoardSymb() const;
		char GetPlayerWheelsSymb() const;
		void SetStartCoord(const int playerCoordX, const int playerCoordY);
	private:
		int coordX_;
		int coordY_;
		char centrSymb;
		char boardSymb;
		char wheelsSymb;
	};
}