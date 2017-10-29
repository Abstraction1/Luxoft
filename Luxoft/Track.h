#pragma once

namespace racing
{
	class Player;
	class Cash;

	class Track
	{
	public:
		Track();
		int GetWidth() const;
		int GetHeight() const;
		void Initialization(const int& width, const int& height);
		char** GetArea() const;
		void SetArea(const int& coordX, const int& coordY, const char symb);
		~Track();
	private:
		int width_;
		int height_;
		char** trackArea_;
		racing::Player * player_;
		racing::Cash * cash_;
	};
}
