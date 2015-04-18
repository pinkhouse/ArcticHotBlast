#include<iostream>
#include"Game.h"
#include<ctime>

int main(int argc, char* argv[])
{
	srand(time(NULL));
	Game* game = new Game();
	return game->run();
}