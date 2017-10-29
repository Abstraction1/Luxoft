#pragma once

namespace racing
{
	class Obstacle
	{
	private:
		int obstCoordX_;
		int obstCoordY_;
		char obstCentrSymb_;
		char obstBoardSymb_;
		char obstWheelsSymb_;
	public:
		Obstacle();
		int GetX() const;
		int GetY() const;
		char GetObstCentrSymb() const;
		char GetObstBoardSymb() const;
		char GetObstWheelsSymb() const;		
		void SetObstStartCoord(const int coordX, const int coordY);
	};
}