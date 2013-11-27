#include "Player.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////


Player::Player(void)
{
	BodyParts.Resize(5000);
	AmountOfBodyParts=0;
	texture.loadFromFile("Circle.png");
	sprite.setTexture(texture);
	speed = 4;
	Rotation = 0;
	X=0;
	Y=0;
	Volicity = sf::Vector2f(sin(3.1456*Rotation/ 180)*speed,cos(3.1456*Rotation/ 180)*speed);
	size = 5;
	spawnBodyParts=0;
	SpawnTimeElapsed =0;
	color = sf::Color::Red;
	sprite.setColor(color);
}


Player::~Player(void)
{

}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(pKeys[0]))
	{
		Rotation++;
	}
	if (sf::Keyboard::isKeyPressed(pKeys[1]))
	{
		Rotation--;
	}
}

int Player::GetSize() const
{
	return size;
}

void Player::SetSize( int val )
{
	size = val;
}

float Player::GetSpeed() const
{
	return speed;
}

void Player::SetSpeed( float val )
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
	SpawnTimeElapsed+= TimeElapsed;
	SpawnBody();
	Move();
	Volicity = sf::Vector2f(sin(3.1456*Rotation/ 180)*speed,cos(3.1456*Rotation/ 180)*speed);
	X += Volicity.x;
	Y += Volicity.y;
	sprite.setPosition(X,Y);
}

void Player::SpawnBody()
{
	if (spawnBodyParts)
	{
		BodyParts.push_back(Body(texture,X,Y,color));
		AmountOfBodyParts++;
	}
}
void Player::ResetBody()
{
	BodyParts.ResetVector();
	AmountOfBodyParts=0;
}

MyVector<Body> & Player::GetBodyParts()
{
	return BodyParts;
}

void Player::RenderBody( sf::RenderWindow & window )
{
	for (int i = AmountOfBodyParts-1; i > 0; i--)
	{
		BodyParts.At(i).Draw(window);
	}
}

sf::Keyboard::Key * Player::Keys()
{
	return pKeys;
}

void Player::SetColor(sf::Color color)
{
	this->color = color;
	sprite.setColor(this->color);
}