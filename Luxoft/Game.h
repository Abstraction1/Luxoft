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
		void Initialization(racing::Track* track, racing::Player* player,
							racing::Obstacle* obstacle, racing::Cash* cash);
		void Print(const racing::Track* track);
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
		enum DIR { DIR_STOP = 0, DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN };
		DIR dir;
	};
}