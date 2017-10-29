#pragma once

namespace racing
{
	class Cash
	{
	public:
		Cash();
		int GetX() const;
		int GetY() const;
		char GetCashSymb() const;
		const int SetRandCoord();
	private:
		int coordX_;
		int coordY_;
		char cashSymb_;
	};
}