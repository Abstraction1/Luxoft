#include "Track.h"

racing::Track::Track()
{
	SetStartCoord();
}

racing::Track::~Track()
{
	for (int i = 0; i < trackCoordX_; i++)
	{
		delete[] trackArea_[i];
	}

	delete[] trackArea_;
}

void racing::Track::CreateTrack()
{
	trackArea_ = new char*[trackCoordY_];

	for (int i = 0; i < trackCoordX_; i++)
	{
		trackArea_[i] = new char[trackCoordX_];
	}
}

int racing::Track::GetX() const
{
	return trackCoordX_;
}

int racing::Track::GetY() const
{
	return trackCoordY_;
}

void racing::Track::SetStartCoord()
{
	trackCoordX_ = 20;
	trackCoordY_ = 20;
	trackArea_ = 0;
}
