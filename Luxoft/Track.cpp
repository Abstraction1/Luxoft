#include "Track.h"
#include "Player.h"
#include "Cash.h"

racing::Track::Track()
{
	width_ = 20;
	height_ = 20;
	Initialization(width_, height_);
}

racing::Track::~Track()
{
	int i;
	
	for (i = 0; i < width_; i++) {
		delete[i] trackArea_;
	}

	delete[] trackArea_;
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
	int i;
	trackArea_ = new char*[width];
	for (i = 0; i < height; i++) {
		trackArea_[i] = new char[height];
	}
}

char ** racing::Track::GetArea() const
{
	return trackArea_;
}

void racing::Track::SetArea(const int& coordX, const int& coordY, const char symb)
{
	int i, j;
	for (i = 0; i < width_; i++) {
		for (j = 0; j < height_; j++) {
			trackArea_[i][j] = symb;
		}
	}
}




