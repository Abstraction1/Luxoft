#pragma once
namespace racing
{
	class Track
	{
	public:
		int WIDTH;
		int HEIGHT;
		char** area;

		Track();
		~Track();
		void CreateTrack();
	};
}