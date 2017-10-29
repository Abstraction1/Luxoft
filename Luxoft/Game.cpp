
#include "Cash.h"
#include "Game.h"
#include "Obstacle.h"
#include "Player.h"
#include "Track.h"

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

racing::Game::Game()
{
	isGameOver = false;
	playerPoints = 0;
	gameSpeed = 200;
	speedometer = 50;
	exitGame = '27';

	track = new racing::Track();
	player = new racing::Player();
	cash = new racing::Cash();
	obstacle = new racing::Obstacle();

	srand((unsigned int)time(NULL));
	track->CreateTrack();
	Run();
}

void racing::Game::Initialization()
{
	dir = DIR_STOP;

	for (int i = 0; i < track->HEIGHT; i++)
	{
		for (int j = 0; j < track->WIDTH; j++)
		{
			track->area[i][0] = '|';
			track->area[i][track->HEIGHT - 2] = '|';
			track->area[i][j] = ' ';
		}
	}

	//car initialization
	track->area[player->x][player->y - 1] = player->left_board;
	track->area[player->x][player->y + 1] = player->right_board;
	track->area[player->x - 1][player->y - 1] = player->wheels;
	track->area[player->x - 1][player->y + 1] = player->wheels;
	track->area[player->x + 1][player->y - 1] = player->wheels;
	track->area[player->x + 1][player->y + 1] = player->wheels;

	//cash initialization
	track->area[cash->x][cash->y] = cash->cash_symb;

	//obstacle initialization
	track->area[obstacle->x][obstacle->y] = obstacle->car;
	track->area[obstacle->x][obstacle->y - 1] = obstacle->left_board;
	track->area[obstacle->x][obstacle->y + 1] = obstacle->right_board;
	track->area[obstacle->x - 1][obstacle->y - 1] = obstacle->wheels;
	track->area[obstacle->x - 1][obstacle->y + 1] = obstacle->wheels;
	track->area[obstacle->x + 1][obstacle->y - 1] = obstacle->wheels;
	track->area[obstacle->x + 1][obstacle->y + 1] = obstacle->wheels;
}

void racing::Game::Print()
{
	for (int i = 0; i < track->HEIGHT; i++)
	{
		for (int j = 0; j < track->WIDTH; j++)
		{
			std::cout<< track->area[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "x : " << obstacle->x << '\n';
	std::cout << "y : " << obstacle->y << '\n';

	std::cout << "\nspeedometer : " << speedometer << '\n';
	std::cout << "\npoints: " << playerPoints;
}

void racing::Game::Run()
{
	while (!isGameOver)
	{
		Input();
		Logic(playerPoints, gameSpeed, speedometer, playStop);
		Initialization();
		Print();
		Sleep(gameSpeed);
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
			isGameOver = true;
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
	cash->x += 2;
	if (cash->x >= track->WIDTH - 1)
	{
		cash->x = 0;
		cash->y = rand() % 16 + 1;
	}
	if (cash->x == player->x && cash->y == player->y ||
		cash->x == player->x + 1 && cash->y == player->y ||
		cash->x == player->x - 1 && cash->y == player->y ||
		cash->x == player->x + 1 && cash->y + 1 == player->y ||
		cash->x == player->x + 1 && cash->y - 1 == player->y ||
		cash->x == player->x - 1 && cash->y + 1 == player->y ||
		cash->x == player->x - 1 && cash->y - 1 == player->y)
	{
		cash->x = 0;
		cash->y = rand() % 16 + 1;
		points += 10;
	}

	//obstacle
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
		gameSpeed = true;
	}
}