#include "Body.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

Body::Body(void)
{
	X=0;
	Y=0;
	size =0;
	Width =0;
	Height=0;
}

Body::Body(sf::Texture & texture)
{
	sprite = sf::Sprite();
	this->texture = texture;
	sprite.setTexture(texture);
}

Body::Body(sf::Texture & texture, float X, float Y,sf::Color & color,float size,int width,int height)
{
	this->texture = texture;
	this->X=X;
	this->Y=Y;
	this->size = size;
	Width = width;
	Height = height;
	sprite.setTexture(texture);
	sprite.setPosition(X,Y);
	sprite.setColor(color);
	//sprite.setScale(this->size);
}

Body::~Body(void)
{

}
void Body::SetTexture( sf::Texture texture )
{
	this->texture = texture;
	UpdateSprite();
}

void Body::UpdateSprite()
{
	sprite.setTexture(texture);
}

void Body::SetColor( sf::Color color )
{
	sprite.setColor(color);
}