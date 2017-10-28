#pragma once

namespace racing
{
	class Player
	{
	public:
		int x;
		int y;
		char car = 'X';
		char left_board = '|';
		char right_board = '|';
		char wheels = 'o';

		Player();
	};
}