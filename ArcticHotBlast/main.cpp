#include<iostream>
#include"Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	return game->run();
}