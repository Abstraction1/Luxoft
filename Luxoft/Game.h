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
		bool isGameOver;
		int	 playerPoints;
		int  gameSpeed;
		int  speedometer;
		char playStop;
		char exitGame;

		racing::Track * track;
		racing::Player * player;
		racing::Cash * cash;
		racing::Obstacle * obstacle;

		enum e_direct { DIR_STOP = 0, DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN };
		e_direct dir;

		Game();
		void Logic(int& points, int& speed, int& speedometer, char& playStop);
		void Initialization();
		void Print();
		void Run();
		void Input();
		void clearScreen();
	};
}