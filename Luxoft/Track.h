#pragma once

namespace racing
{
	class Player;
	class Cash;

	class Track
	{
	public:
		Track();
		int GetWidth() const
		{
			return width_;
		}
		int GetHeight() const
		{
			return height_;
		}
		char** GetArea() const
		{
			return trackArea_;
		}
		void Initialization(const int& width, const int& height);
		void SetArea(const int& coordX, const int& coordY, const char* symb);
		~Track();
	private:
		int width_;
		int height_;
		char trackBoard_;
		char trackSpace_;
		char** trackArea_;
		racing::Player * player_;
		racing::Cash * cash_;
	};
}
