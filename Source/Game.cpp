#include "Header/Player.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>

racing::Game::Game()
{
	srand(time(NULL));

	track = new racing::Track();
	player = new racing::Player();
	cash = new racing::Cash();
	obstacle = new racing::Obstacle();

	track->CreateTrack();

	game_over = false;
	player_points = 0;
	game_speed = 200;
	speedometer = 50;

	Run();
}

void racing::Game::Initialization()
{
	dir = STOP;

	//track initialization
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
	track->area[player->x][player->y] = player->car;
	track->area[player->x][player->y - 1] = player->left_board;
	track->area[player->x][player->y + 1] = player->right_board;
	track->area[player->x - 1][player->y - 1] = player->wheels;
	track->area[player->x - 1][player->y + 1] = player->wheels;
	track->area[player->x + 1][player->y - 1] = player->wheels;
	track->area[player->x + 1][player->y + 1] = player->wheels;

	//cash initialization
	track->area[cash->x][cash->y] = cash->cash_symb;

	//osbtracle initialization
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
			std::cout << track->area[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "X : " << obstacle->x << '\n';
	std::cout << "Y : " << obstacle->y << '\n';

	std::cout << "\nSpeedometr : " << speedometer << '\n';
	std::cout << "\nPoints: " << player_points;
}

void racing::Game::Run()
{
	while (!game_over)
	{
		input();
		Logic(player_points, game_speed, speedometer, play_stop);
		Initialization();
		Print();
		Sleep(game_speed);
		clearscreen();
	}
}

void racing::Game::input()
{
	while (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 27:
			game_over = true;
			break;
		}
	}
}

void racing::Game::clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void racing::Game::Logic(int& points, int& speed, int& speedometer, char& play_stop)
{
	switch (dir)
	{
	case racing::Game::LEFT:
		player->y = player->y - 2;
		break;
	case racing::Game::RIGHT:
		player->y = player->y + 2;
		break;
	case racing::Game::UP:
		speed -= 5;
		speedometer += 5;
		break;
	case racing::Game::DOWN:
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
	cash->x+=2;
	if (cash->x >= track->WIDTH - 1)
	{
		cash->x = 0;
		cash->y = rand () % 16 + 1;
	}
	if (cash->x == player->x && cash->y == player->y ||
		cash->x == player->x + 1 && cash->y == player->y ||
		cash->x == player->x - 1 && cash->y == player->y ||
		cash->x == player->x + 1 && cash->y + 1== player->y ||
		cash->x == player->x + 1 && cash->y - 1 == player->y ||
		cash->x == player->x - 1 && cash->y + 1 == player->y ||
		cash->x == player->x - 1 && cash->y - 1 == player->y)
	{
		cash->x = 0;
		cash->y = rand() % 16 + 1;
		points +=10;
	}

	//obstracle
	obstacle->x++;
	if (obstacle->x == track->WIDTH	- 1)
	{
		obstacle->x = 1;
		obstacle->y = rand() % 15 + 2;
	}
	if (obstacle->x + 1 == player->x + 1 && obstacle->y - 1 == player->y - 1 ||
		obstacle->x - 1 == player->x + 1 && obstacle->y + 1 == player->y + 1 ||
		obstacle->x == player->x && obstacle->y == player->y ) 
	{
		game_over = true;
	}
}
