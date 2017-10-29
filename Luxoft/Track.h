#pragma once

namespace racing
{
	class Track
	{
	public:
		Track();
		int GetWidth() const;
		int GetHeight() const;
		void Initialization(const int& width, const int& height);
		const char** GetArea();
		void SetArea(const int& coordX, const int& coordY);
		~Track();
	private:
		int width_;
		int height_;
		char** trackArea_;
		racing::Player * player_;
		racing::Cash * player_;
	};
}
