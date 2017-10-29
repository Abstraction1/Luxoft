#pragma once

namespace racing
{
	class Player
	{
	public:
		Player();
		int GetX() const
		{
			return coordX_;
		}
		int GetY() const
		{
			return coordY_;
		}
		char* GetSymb() const
		{
			return symb_;
		}
		void SetStartCoord(const int coordX, const int coordY);
		~Player();
	private:
		int coordX_;
		int coordY_;
		char * symb_;
	};
}