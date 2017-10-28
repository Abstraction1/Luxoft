#include "Track.h"

racing::Track::Track()
{
	WIDTH = 20;
	HEIGHT = 20;
	area = 0;
}

racing::Track::~Track()
{
	for (int i = 0; i < WIDTH; i++)
	{
		delete[] area[i];
	}
	delete[] area;
}

void racing::Track::CreateTrack()
{
	area = new char*[HEIGHT];
	for (int i = 0; i < WIDTH; i++)
	{
		area[i] = new char[WIDTH];
	}
}
