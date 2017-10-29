#pragma once

namespace racing
{
	class Track
	{
	private:
		int trackCoordX_;
		int trackCoordY_;
		char** trackArea_;
	public:
		Track();
		~Track();
		void CreateTrack();
		int GetX() const;
		int GetY() const;
		void SetStartCoord();
	};
}
