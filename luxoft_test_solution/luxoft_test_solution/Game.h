#pragma once

#include "Track.h"
#include "Player.h"
#include "Cash.h"

namespace Racing
{
	class Player;
	class Track;

	class Game
	{
	public:
		int player_points;
		int game_speed;
		Racing::Track * track;
		Racing::Player * player;
		Racing::Cash * cash;

		enum e_direct { STOP = 0, LEFT, RIGHT, UP, DOWN };
		e_direct dir;

		Game();
		void Logic();
		void Initialization();
		void Print();
		void Run();
		void input();
		void clearscreen();

	};
}