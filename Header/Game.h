#pragma once

#include "Track.h"
#include "Player.h"
#include "Cash.h"
#include "Obstacle.h"

namespace racing
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

		racing::Track * track;
		racing::Player * player;
		racing::Cash * cash;
		racing::Obstacle * obstacle;

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