#include "Player.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////


Player::Player(void)
{
	startHole = 40;
	endHole = 60;
	BodyParts.Resize(10000);
	AmountOfBodyParts=0;
	texture.loadFromFile("Circle.png");
	sprite.setTexture(texture);
	Width = texture.getSize().x;
	Height = texture.getSize().y;
	speed = 1;
	Rotation = 0;
	RotationSpeed=2;
	X=1;
	Y=1;
	Volicity = sf::Vector2f((float)sin(3.1456*Rotation/ 180)*speed,(float)cos(3.1456*Rotation/ 180)*speed);
	size = 1;
	spawnBodyParts=true;
	canMoveHead = true;
	SpawnTimeElapsed =0;
	color = sf::Color::Red;
	sprite.setColor(color);
	sprite.setScale(size,size);
	alive = true;
	spawnsToBeMade=0;
	score =0;
	Body temp;
	SpawnRateInMilis = 0;
	canColide = true;
	powerUppColideActive=false;
}


Player::~Player(void)
{

}

void Player::Move()
{
	if (canMoveHead)
	{
		if (sf::Keyboard::isKeyPressed(pKeys[0]))
		{
			Rotation += RotationSpeed;
		}
		if (sf::Keyboard::isKeyPressed(pKeys[1]))
		{
			Rotation -= RotationSpeed;
		}
		Volicity = sf::Vector2f((float)sin(3.1456*Rotation/ 180)*speed,(float)cos(3.1456*Rotation/ 180)*speed);
		X += Volicity.x;
		Y += Volicity.y;
		sprite.setPosition(X,Y);
	}
}

float Player::GetSize() const
{
	return size;
}

void Player::SetSize( float val )
{
	size = val;
	sprite.setScale(size,size);

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
	sprite.setTexture(texture);
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
	
}

void Player::SpawnBody()
{
	spawnsToBeMade++;
	if (spawnBodyParts && SpawnTimeElapsed >= SpawnRateInMilis &&  spawnsToBeMade%endHole < startHole)
	{
		if(spawnsToBeMade> endHole-2)
		{
			spawnsToBeMade = 0;
			endHole = rand()%50+80;
			startHole = endHole-rand()%20-10;
		}
		if (!(powerUppColideActive))
		{
			canColide = true;
		}

		BodyParts.push_back(Body(texture,X,Y,color,size,Width,Height));
		AmountOfBodyParts++;
		SpawnTimeElapsed = 0;
	}
	else 
	{
		canColide = false;
	}
}
void Player::SpawnBody(float x,float y)
{
	if (spawnBodyParts && SpawnTimeElapsed >= SpawnRateInMilis)
	{
		BodyParts.push_back(Body(texture,x,y,color,size,Width,Height));
		AmountOfBodyParts++;
		SpawnTimeElapsed = 0;
	}
}
void Player::ResetBody()
{
	spawnsToBeMade =0;
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

bool Player::intersectToBody( Player& player )
{
	for (int i=player.BodyParts.Size()-1; i >0; i--)
	{
		if(canColide && intersect(player.BodyParts.At(i)))
		{
			canMoveHead = false;
			spawnBodyParts = false;
			alive = false;
			return true;
		}
	}

	return false;
}

bool Player::IsAlive() const
{
	return alive;
}

void Player::IsAlive( bool val )
{
	alive = val;
}

int Player::Score() const
{
	return score;
}

void Player::Score( int val )
{
	score = val;
}
void Player::AddScore()
{
	score++;
}

bool Player::intersectWall( Rectangle &gameBounds )
{
	if (canColide)
	{
		if (X > gameBounds.GetWidth() || X < gameBounds.GetX() || Y > gameBounds.GetHeight() || Y < gameBounds.GetY())
		{
			canMoveHead = false;
			spawnBodyParts = false;
			alive = false;
			return true;
		}
	}
	return false;
}

void Player::SetRotationSpeed( float rot )
{
	RotationSpeed = rot;
}

float Player::GetRotationSpeed()
{
	return RotationSpeed;
}

void Player::SemiResetPlayer(float X,float Y,sf::Color color)
{
	startHole = 40;
	endHole = 60;
	BodyParts.Resize(5000);
	AmountOfBodyParts=0;
	texture.loadFromFile("Circle.png");
	sprite.setTexture(texture);
	Width = texture.getSize().x;
	Height = texture.getSize().y;
	speed = 1;
	Rotation = 0;
	RotationSpeed=2;
	this->X=X;
	this->Y=Y;
	Volicity = sf::Vector2f((float)sin(3.1456*Rotation/ 180)*speed,(float)cos(3.1456*Rotation/ 180)*speed);
	size = 1;
	spawnBodyParts=true;
	canMoveHead = true;
	SpawnTimeElapsed =0;
	this->color = color;
	sprite.setColor(color);
	sprite.setScale(size,size);
	alive = true;
	spawnsToBeMade=0;
	SpawnRateInMilis = 0;
	canColide = true;
	powerUppColideActive=false;
	BodyParts.ResetVector();
	sprite.setPosition(X,Y);
}

void Player::ResetPlayer(float X, float Y,sf::Color color)
{
	startHole = 40;
	endHole = 60;
	BodyParts.Resize(5000);
	AmountOfBodyParts=0;
	texture.loadFromFile("Circle.png");
	sprite.setTexture(texture);
	Width = texture.getSize().x;
	Height = texture.getSize().y;
	speed = 1;
	Rotation = 0;
	RotationSpeed=2;
	this->X=X;
	this->Y=Y;
	Volicity = sf::Vector2f((float)sin(3.1456*Rotation/ 180)*speed,(float)cos(3.1456*Rotation/ 180)*speed);
	size = 1;
	spawnBodyParts=true;
	canMoveHead = true;
	SpawnTimeElapsed =0;
	this->color = color;
	sprite.setColor(color);
	sprite.setScale(size,size);
	alive = true;
	spawnsToBeMade=0;
	SpawnRateInMilis = 0;
	canColide = true;
	powerUppColideActive=false;
	score = 0;
	BodyParts.ResetVector();
	sprite.setPosition(X,Y);
}

bool Player::intersectToOwnBody()
{
	for (int i=BodyParts.Size()-20; i >0; i--)
	{
		if(canColide && intersect(BodyParts.At(i)))
		{
			canMoveHead = false;
			spawnBodyParts = false;
			alive = false;
			return true;
		}
	}

	return false;
}

int Player::GetScore()
{
	return score;
}
