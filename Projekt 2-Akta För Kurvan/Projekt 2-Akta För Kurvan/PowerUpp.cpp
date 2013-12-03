#include "PowerUpp.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

PowerUpp::PowerUpp(void)
{
	owner = nullptr;
	duration= 5000;
	active = false;
	type =0;
}

PowerUpp::PowerUpp( PowerUpp &powerUpp )
{
	active = powerUpp.active;
	duration = powerUpp.duration;
	Height = powerUpp.Height;
	owner = powerUpp.owner;
	size = powerUpp.size;
	texture = sf::Texture(powerUpp.texture);
	sprite = sf::Sprite(powerUpp.sprite);
	sprite.setTexture(texture);
	Width = powerUpp.Width;
	X = powerUpp.X;
	Y = powerUpp.Y;
	type = powerUpp.type;
}


PowerUpp::~PowerUpp(void)
{

}

float PowerUpp::GetDuration() const
{
	return duration;
}

void PowerUpp::SetDuration( float val )
{
	duration = val;
}

void PowerUpp::ApplyBuff( Player * player, int corrent, int size)
{
	sizeOfPlayers = size;
	this->corrent = corrent;
	switch (type)
	{
	case 0:
		{
			player[corrent].SetSpeed(player[corrent].GetSpeed()*1.5f);

			break;
		}
	case 1:
		{
			for (int i=0; i < sizeOfPlayers; i++)
			{
				if (i != corrent)
				{
					player[i].SetSpeed(player[i].GetSpeed()/2);
					player[i].SetRotationSpeed(player[i].GetRotationSpeed()/2);
				}
			}
			break;
		}
	}
}

void PowerUpp::UnApplyBuff( Player * player, int corrent, int size)
{
	sizeOfPlayers = size;
	this->corrent = corrent;
	switch (type)
	{
	case 0:
		{
			player[corrent].SetSpeed(player[corrent].GetSpeed()/1.5f);
			break;
		}
	case 1:
		{
			for (int i=0; i < sizeOfPlayers; i++)
			{
				if (i != corrent)
				{
					player[i].SetSpeed(player[i].GetSpeed()*2);
					player[i].SetRotationSpeed(player[i].GetRotationSpeed()*2);
				}
			}
			break;
		}
	}
}

bool PowerUpp::UpdateBuff( float TimeElapsed)
{
	if (active)
	{
		duration -= TimeElapsed;
		if (duration <= 0)
		{
			UnApplyBuff(owner,corrent,sizeOfPlayers);
			return true;
		}
	}
	return false;
}

Player PowerUpp::GetOwner() const
{
	return *owner;
}

void PowerUpp::SetOwner( Player * player, int corrent, int size)
{
	this->corrent = corrent;
	sizeOfPlayers = size;
	owner = player;
}

void PowerUpp::SetActive(bool active)
{
	this->active = active;
}

void PowerUpp::DrawBuff(sf::RenderWindow & window)
{
	if (!active)
	{
		Draw(window);
	}
}

void PowerUpp::SetType( int type )
{
	this->type = type;
	switch (type)
	{
	case 0:
		{
			duration = 5000;
			texture.loadFromFile("Speed.png");
			break;
		}
	case 1:
		{
			duration = 3500;
			texture.loadFromFile("ASpeed.png");
			break;
		}
	}
	Width = texture.getSize().x;
	Height = texture.getSize().y;
	sprite.setTexture(texture);
}

int PowerUpp::GetType()
{
	return type;
}

bool PowerUpp::GetActive()
{
	return active;
}
