#pragma once

#include "Track.h"
#include "Player.h"
#include "Cash.h"
#include "Obstacle.h"

namespace racing
{
	class Game
	{
	public:
		Game();
		void Logic(int& points, int& speed, int& speedometer, char& playStop);
		void Initialization();
		void Print();
		void Run();
		void Input();
		void clearScreen();
	private:
		racing::Track* track_;
		racing::Player* player_;
		racing::Cash* cash_;
		racing::Obstacle* obstacle_;
		bool isGameOver_;
		int	 playerPoints_;
		int  gameSpeed_;
		int  speedometer_;
		char exitGame_;
		char playStop_;
		char** trackArea_;
		enum e_direct { DIR_STOP = 0, DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_EXIT };
		e_direct DIR;
	};
}