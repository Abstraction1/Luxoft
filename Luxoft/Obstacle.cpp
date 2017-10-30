#include "Obstacle.h"
#include <cstdlib>

Racing::Obstacle::Obstacle()
{
	x = 1;
	y = rand() % 16 + 2;
}