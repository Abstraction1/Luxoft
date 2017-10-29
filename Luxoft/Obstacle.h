#pragma once

namespace racing
{
	class Obstacle
	{
	public:
		Obstacle();
		int GetX() const {
			return coordX_;
		}
		int GetY() const {
			return coordY_;
		}
		char* GetSymb() const {
			return symbols_;
		}
		void SetStartCoord(const int coordX, const int coordY);
	private:
		int coordX_;
		int coordY_;
		char * symb_;
	};
}