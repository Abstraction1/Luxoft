#pragma once

namespace racing
{
	class Obstacle
	{
	public:
		int x;
		int y;
		char car = '-';
		char left_board = '|';
		char right_board = '|';
		char wheels = 'o';

		Obstacle();
	};
}