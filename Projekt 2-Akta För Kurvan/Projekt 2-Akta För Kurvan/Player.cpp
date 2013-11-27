#include "Player.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////


Player::Player(void)
{
	texture.loadFromFile("Circle.png");
	sprite.setTexture(texture);
	speed = 5;
	size = 5;
}


Player::~Player(void)
{

}

void Player::Move()
{

}

int Player::GetSize() const
{
	return size;
}

void Player::SetSize( int val )
{
	size = val;
}

double Player::GetSpeed() const
{
	return speed;
}

void Player::SetSpeed( double val )
{
	speed = val;
}

void Player::SetTexture( sf::Texture texture )
{
	this->texture = texture;
}

void Player::UpdateSprite()
{
	sprite.setTexture(texture);
}

void Player::Update( double TimeElapsed )
{

}
