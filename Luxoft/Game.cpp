#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

#include "Cash.h"
#include "Game.h"
#include "Obstacle.h"
#include "Player.h"
#include "Track.h"

racing::Game::Game()
{
	srand((unsigned int)time(NULL));

	track_ = new racing::Track();
	player_ = new racing::Player();
	cash_ = new racing::Cash();
	obstacle_ = new racing::Obstacle();

	isGameOver_ = false;
	playerPoints_ = NULL;
	gameSpeed_ = 200;
	speedometer_ = 50;
	exitGame_ = '27';
	//DIR = DIR_STOP;
	Run();
}

void racing::Game::Initialization(racing::Track & track, racing::Player & player,
									racing::Obstacle & obstacle, racing::Cash & cash)
{
	int playerX = player.GetX();
	int playerY = player.GetY();
	int cashX = track.GetWidth();
	int cashY = track.GetHeight();
	int obstacleX = obstacle.GetX();
	int obstacleY = obstacle.GetY();

	track.SetArea(playerX, playerY);
	track.SetArea(cashX, cashY);

	/*track->area[player->x][player->y - 1] = player->left_board;
	track->area[player->x][player->y + 1] = player->right_board;
	track->area[player->x - 1][player->y - 1] = player->wheels;
	track->area[player->x - 1][player->y + 1] = player->wheels;
	track->area[player->x + 1][player->y - 1] = player->wheels;
	track->area[player->x + 1][player->y + 1] = player->wheels;*/
	//cash initialization
	//track->area[Cash()->x][Cash()->y] = Cash()->cash_symb;
	//obstacle initialization
	/*track->area[obstacle->x][obstacle->y] = obstacle->car;
	track->area[obstacle->x][obstacle->y - 1] = obstacle->left_board;
	track->area[obstacle->x][obstacle->y + 1] = obstacle->right_board;
	track->area[obstacle->x - 1][obstacle->y - 1] = obstacle->wheels;
	track->area[obstacle->x - 1][obstacle->y + 1] = obstacle->wheels;
	track->area[obstacle->x + 1][obstacle->y - 1] = obstacle->wheels;
	track->area[obstacle->x + 1][obstacle->y + 1] = obstacle->wheels;*/
}

void racing::Game::Print()
{
	int i, j;
	for (i = 0; i < track->GetHeight(); i++) {
		for (j = 0; j < track->GetWidth(); j++) { 
			
		}
	}
}

void racing::Game::Run()
{
	while (!isGameOver_)
	{
		Input();
		Logic(playerPoints_, gameSpeed_, speedometer_, playStop_);
		Initialization();
		Print();
		Sleep(gameSpeed_);
		clearScreen();
	}
}

void racing::Game::Input()
{
	while (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			dir = racing::Game::DIR_UP;
			break;
		case 's':
			dir = racing::Game::DIR_DOWN;
			break;
		case 'a':
			dir = racing::Game::DIR_LEFT;
			break;
		case 'd':
			dir = racing::Game::DIR_RIGHT;
			break;
		case 27:
			isGameOver_ = true;
			break;
		}
	}
}

void racing::Game::clearScreen()
{
	HANDLE hout;
	COORD position;

	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(hout, position);
}

void racing::Game::Logic(int & points, int & speed, int & speedometer, char & playStop)
{
	switch (dir)
	{
	case racing::Game::DIR_LEFT:
		player->y = player->y - 2;
		break;
	case racing::Game::DIR_RIGHT:
		player->y = player->y + 2;
		break;
	case racing::Game::DIR_UP:
		speed -= 5;
		speedometer += 5;
		break;
	case racing::Game::DIR_DOWN:
		speed += 5;
		speedometer -= 5;
		break;
	}

	//player
	if (player->y <= 2)
	{
		player->y = 2;
	}
	if (player->y >= track->WIDTH - 4)
	{
		player->y = track->WIDTH - 4;
	}
	if (player->x <= 1)
	{
		player->x = 1;
	}
	if (player->x >= track->WIDTH - 2)
	{
		player->x = track->WIDTH - 2;
	}

	//cash
	Cash()->x += 2;
	if (Cash()->x >= track->WIDTH - 1)
	{
		Cash()->x = 0;
		Cash()->y = rand() % 16 + 1;
	}
	if (MyMethod();

		Cash()->x = 0;
		Cash()->y = rand() % 16 + 1;
		points += 10;
	}

	//obstacke
	obstacle->x++;
	if (obstacle->x == track->WIDTH - 1)
	{
		obstacle->x = 1;
		obstacle->y = rand() % 15 + 2;
	}
	if (obstacle->x + 1 == player->x + 1 && obstacle->y - 1 == player->y - 1 ||
		obstacle->x - 1 == player->x + 1 && obstacle->y + 1 == player->y + 1 ||
		obstacle->x == player->x && obstacle->y == player->y)
	{
		gameSpeed_ = true;
	}
}


