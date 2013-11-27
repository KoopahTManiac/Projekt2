#include "Body.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

Body::Body(void)
{
	texture.loadFromFile("Circle.png");
}

Body::Body(sf::Texture texture)
{
	this->texture = texture;
}

Body::~Body(void)
{

}
void Body::SetTexture( sf::Texture texture )
{
	this->texture = texture;
}

void Body::UpdateSprite()
{
	sprite.setTexture(texture);
}

