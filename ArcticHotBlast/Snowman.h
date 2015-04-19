#pragma once

#include "Enemy.h"
#include "SnowBall.h"

class Snowman:
	public Enemy
{
public:
	Snowman();
	~Snowman();

private:
	SnowBall head;
	SnowBall middle;
	SnowBall bottom;
};

