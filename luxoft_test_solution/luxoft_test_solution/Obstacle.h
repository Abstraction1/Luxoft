#pragma once
namespace Racing
{
	class Obstacle
	{
	public:
		int x;
		int y;
		char car = 'E';
		char left_board = '|';
		char right_board = '|';
		char wheels = 'o';

		Obstacle();
	};
}