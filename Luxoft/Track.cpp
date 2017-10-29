#include "Track.h"
#include "Player.h"
#include "Cash.h"

racing::Track::Track()
{
	width_ = 20;
	height_ = 20;
	trackBoard_ = '|';
	trackSpace_ = ' ';

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

void racing::Track::Initialization(const int& width, const int& height)
{
	int i, j;
	trackArea_ = new char*[width];
	for (i = 0; i < height; i++) {
		trackArea_[i] = new char[height];
	}
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			trackArea_[i][0] = trackBoard_;
			trackArea_[i][height - 2] = trackBoard_;
			trackArea_[i][j] = trackSpace_;
		}
	}
}

void racing::Track::SetArea(const int& coordX, const int& coordY, 
							const char* symb)
{
	trackArea_[coordX][coordY] = symb[0];
	trackArea_[coordX + 1][coordY] = symb[1];
	trackArea_[coordX - 1][coordY] = symb[1];
	trackArea_[coordX - 1][coordY - 1] = symb[2];
	trackArea_[coordX - 1][coordY + 1] = symb[2];
	trackArea_[coordX + 1][coordY + 1] = symb[2];
	trackArea_[coordX + 1][coordY - 1] = symb[2];
}




