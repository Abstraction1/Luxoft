#include "Track.h"

racing::Track::Track()
{
	
}

racing::Track::~Track()
{

}

int racing::Track::GetWidth() const
{
	return width_;
}

int racing::Track::GetHeight() const
{
	return height_;
}

void racing::Track::Initialization(const int & width, const int & height)
{
	int i = 0;

	trackArea_ = new char*[height_];
	for (i = 0; i < width_; i++) {
		trackArea_[i] = new char[width_];
	}
}


