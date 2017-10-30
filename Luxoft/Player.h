#pragma once
namespace Racing
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