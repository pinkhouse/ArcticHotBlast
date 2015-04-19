#include "SnowBall.h"


SnowBall::SnowBall()
{
}


SnowBall::~SnowBall()
{
}


void SnowBall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(snowBall);
}