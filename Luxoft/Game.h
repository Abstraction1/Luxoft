#pragma once

#include "Track.h"
#include "Player.h"
#include "Cash.h"
#include "Obstacle.h"

namespace Racing
{
	class Player;
	class Track;

	class Game
	{
	public:
		bool game_over;
		int player_points;
		int game_speed;
		int speedometer;
		char play_stop;

		Racing::Track * track;
		Racing::Player * player;
		Racing::Cash * cash;
		Racing::Obstacle * obstacle;

		enum e_direct { STOP = 0, LEFT, RIGHT, UP, DOWN };
		e_direct dir;

		Game();
		void Logic(int& points, int& speed, int& speedometer, char& play_stop);
		void Initialization();
		void Print();
		void Run();
		void input();
		void clearscreen();
	};
}