#include "PowerUpp.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

PowerUpp::PowerUpp(void)
{
	duration= 15;
	type=0;
	texture.loadFromFile("Circle.png");
	sprite.setTexture(texture);
}


PowerUpp::~PowerUpp(void)
{

}

int PowerUpp::GetType() const
{
	return type;
}

void PowerUpp::SetType( int val )
{
	type = val;
}

int PowerUpp::GetDuration() const
{
	return duration;
}

void PowerUpp::SetDuration( int val )
{
	duration = val;
}
