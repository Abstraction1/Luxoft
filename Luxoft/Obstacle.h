#pragma once

namespace racing
{
	class Obstacle
	{
	public:
		Obstacle();
		int GetX() const;
		int GetY() const;
		char GetCentrSymb() const;
		char GetBoardSymb() const;
		char GetWheelsSymb() const;		
		void SetStartCoord(const int coordX, const int coordY);
	private:
		int coordX_;
		int coordY_;
		char centrSymb_;
		char boardSymb_;
		char wheelsSymb_;

	};
}