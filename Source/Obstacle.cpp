#include "Obstacle.h"
#include <cstdlib>

racing::Obstacle::Obstacle()
{
	x = 1;
	y = rand () % 16 + 2;
}
