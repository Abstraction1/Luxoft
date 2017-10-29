#pragma once

namespace racing
{
	class Track
	{
	public:
		Track();
		~Track();
		int GetWidth() const;
		int GetHeight() const;
		void Initialization(const int& width, const int& height);
	private:
		int width_;
		int height_;
		char** trackArea_;
	};
}
