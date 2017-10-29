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
	playerPoints_ = 0;
	gameSpeed_ = 200;
	speedometer_ = 50;
	exitGame_ = 27;
	Run();
}

void racing::Game::Initialization()
{
	int playerX = player_->GetX();
	int playerY = player_->GetY();
	int cashX = cash_->GetX();
	int cashY = cash_->GetY();
	int obstacleX = obstacle_->GetX();
	int obstacleY = obstacle_->GetX();
	char* playerSymb = player_->GetSymb();
	char* cashSymb = cash_->GetSymb();
	char* obstSymb = obstacle_->GetSymb();

	track_->SetArea(playerX, playerY, playerSymb);
	track_->SetArea(obstacleX, obstacleY, obstSymb);
	track_->SetArea(cashX, cashY, cashSymb);
}

void racing::Game::Print()
{
	int i, j;
	int width = track_->GetWidth();
	int height = track_->GetHeight();
	trackArea_ = track_->GetArea();

	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			std::cout << trackArea_[i][j];
		}
		std::cout << std::endl;
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
			DIR = racing::Game::DIR_UP;
			break;
		case 's':
			DIR = racing::Game::DIR_DOWN;
			break;
		case 'a':
			DIR = racing::Game::DIR_LEFT;
			break;
		case 'd':
			DIR = racing::Game::DIR_RIGHT;
			break;
		case 27:
			DIR = racing::Game::DIR_EXIT;
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
	switch (DIR)
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
	case racing::Game::DIR_EXIT:
		isGameOver_ = true;
		break;
	}

	//player
	//if (player->y <= 2)
	//{
	//	player->y = 2;
	//}
	//if (player->y >= track->WIDTH - 4)
	//{
	//	player->y = track->WIDTH - 4;
	//}
	//if (player->x <= 1)
	//{
	//	player->x = 1;
	//}
	//if (player->x >= track->WIDTH - 2)
	//{
	//	player->x = track->WIDTH - 2;
	//}

	////cash
	//Cash()->x += 2;
	//if (Cash()->x >= track->WIDTH - 1)
	//{
	//	Cash()->x = 0;
	//	Cash()->y = rand() % 16 + 1;
	//}

	//	Cash()->x = 0;
	//	Cash()->y = rand() % 16 + 1;
	//	points += 10;
	//}

	////obstacle
	//obstacle->x++;
	//if (obstacle->x == track->WIDTH - 1)
	//{
	//	obstacle->x = 1;
	//	obstacle->y = rand() % 15 + 2;
	//}
	//if (obstacle->x + 1 == player->x + 1 && obstacle->y - 1 == player->y - 1 ||
	//	obstacle->x - 1 == player->x + 1 && obstacle->y + 1 == player->y + 1 ||
	//	obstacle->x == player->x && obstacle->y == player->y)
	//{
	//	gameSpeed_ = true;
	//}
}


