#include "Game.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>

Racing::Game::Game()
{
	track = new Racing::Track();
	player = new Racing::Player();
	cash = new Racing::Cash();

	track->CreateTrack();

	player_points = 0;
	game_speed = 150;

	Run();
}

void Racing::Game::Initialization()
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
	//track->area[obstracle->x][obstracle->y] = obstracle->car;
	//track->area[obstracle->x][obstracle->y - 1] = obstracle->left_board;
	//track->area[obstracle->x][obstracle->y + 1] = obstracle->right_board;
	//track->area[obstracle->x - 1][obstracle->y - 1] = obstracle->wheels;
	//track->area[obstracle->x - 1][obstracle->y + 1] = obstracle->wheels;
	//track->area[obstracle->x + 1][obstracle->y - 1] = obstracle->wheels;
	//track->area[obstracle->x + 1][obstracle->y + 1] = obstracle->wheels;
}

void Racing::Game::Print()
{
	for (int i = 0; i < track->HEIGHT; i++)
	{
		for (int j = 0; j < track->WIDTH; j++)
		{
			std::cout << track->area[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << "player x: " << player->x << '\n';
	std::cout << "player y: " << player->y << '\n';
	std::cout << "cash x: " << cash->x << '\n';
	std::cout << "cash y: " << cash->y << '\n';
	std::cout << "obstacle x: " << cash->x << '\n';
	std::cout << "obstacle  y: " << cash->y << '\n';

	std::cout << "\nPLAYER POINTS: " << player_points << '\n';
}

void Racing::Game::Run()
{
	while (true)
	{
		input();
		Logic();
		Initialization();
		Print();
		Sleep(game_speed);
		clearscreen();
	}
}

void Racing::Game::input()
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
		}
	}
}

void Racing::Game::clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void Racing::Game::Logic()
{
	switch (dir)
	{
	case Racing::Game::LEFT:
		player->y = player->y - 2;
		break;
	case Racing::Game::RIGHT:
		player->y = player->y + 2;
		break;
	case Racing::Game::UP:
		game_speed -= 5;
		break;
	case Racing::Game::DOWN:
		game_speed -= 5;
		break;
	}
	//player
	if (player->y <= 2)
	{
		player->y = 2;
	}
	if (player->y >= 16)
	{
		player->y = 16;
	}
	if (player->x <= 1)
	{
		player->x = 1;
	}
	if (player->x >= 18)
	{
		player->x = 18;
	}

	//cash 
	cash->x++;

	if (cash->x >= track->WIDTH - 1)
	{
		cash->x = 0;
		cash->y = rand () % 16 + 1;
	}

	if (cash->x == player->x && cash->y == player->y)
	{
		player_points+=10;
	}

	//obstracle
}
