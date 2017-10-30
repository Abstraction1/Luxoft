#pragma once
namespace Racing
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