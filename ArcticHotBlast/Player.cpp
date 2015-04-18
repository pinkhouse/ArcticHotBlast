#include "Player.h"

Player::Player(sf::Vector2f position)
{
	if (textureBody.loadFromFile("data/img/player/body.png"))
	{
		this->body.setTexture(textureBody);
	}
	if (textureArm.loadFromFile(""))
	{
		this->arm.setTexture(textureArm);
	}

	this->body.setOrigin(body.getLocalBounds().width/2, body.getLocalBounds().height/2);
	this->body.setPosition(position);

	this->armLocation = position;
	this->arm.setOrigin(arm.getLocalBounds().width / 2, 5);
	this->arm.setPosition(armLocation);
	this->gravity = 980.0f;
	this->isGrounded = false;

	this->frameTime = new sf::Time;
}

Player::~Player()
{

}

bool Player::update(sf::Time& frameTime, sf::Event &event)
{
	this->frameTime = &frameTime;
	this->body.move(0,this->gravity * frameTime.asSeconds());
	return false;
}


void Player::checkInput(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.text.unicode == sf::Keyboard::W  && isGrounded)
	{
		
	}
	if (event.type == sf::Event::KeyPressed && event.text.unicode == sf::Keyboard::A)
	{

	}
	if (event.type == sf::Event::KeyPressed && event.text.unicode == sf::Keyboard::D)
	{

	}
	if (event.type == sf::Event::KeyPressed && event.text.unicode == sf::Keyboard::Space)
	{

	}
	
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(arm);
}

