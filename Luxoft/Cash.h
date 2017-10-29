#pragma once

namespace racing
{
	class Cash
	{
	public:
		Cash();
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
		const int SetRandCoord();
		~Cash();
	private:
		int coordX_;
		int coordY_;
		char * symb_;
	};
}