#include "Body.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

Body::Body(void)
{
	texture.loadFromFile("Circle.png");
	sprite = sf::Sprite();
	sprite.setTexture(texture);
}

Body::Body(sf::Texture texture)
{
	sprite = sf::Sprite();
	this->texture = texture;
	sprite.setTexture(texture);
}

Body::Body( sf::Texture texture, float X, float Y, sf::Color color )
{
	size =1;
	sprite = sf::Sprite();
	this->texture = texture;
	this->X=X;
	this->Y=Y;
	sprite.setPosition(X,Y);
	sprite.setTexture(texture);
	sprite.setColor(color);
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