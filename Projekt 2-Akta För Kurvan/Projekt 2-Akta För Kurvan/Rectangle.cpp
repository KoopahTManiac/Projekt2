#include "Rectangle.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////


Rectangle::Rectangle(void)
{
	size =1;
}


Rectangle::~Rectangle(void)
{

}

float Rectangle::GetX() const
{
	return X;
}

float Rectangle::GetY() const
{
	return Y;
}

int Rectangle::GetWidth() const
{
	return Width;
}

int Rectangle::GetHeight() const
{
	return Height;
}

void Rectangle::SetX( float X )
{
	this->X = X;
	sprite.setPosition(X,Y);
}

void Rectangle::SetY( float Y )
{
	this->Y= Y;
	sprite.setPosition(X,Y);
}

void Rectangle::SetWidth( int Width )
{
	this->Width=Width;
}

void Rectangle::SetHeight( int Height )
{
	this->Height=Height;
}

void Rectangle::SetPos( float X,float Y )
{
	this->X=X;
	this->Y=Y;
	sprite.setPosition(X,Y);
}

void Rectangle::SetSize( int Width, int Height )
{
	size = Width / this->Width;
	this->Width = texture.getSize().x*size;
	this->Height = texture.getSize().y*size;
	sprite.setScale(size,size);
}

bool Rectangle::intersect( Rectangle & rect ) const
{
	if (X <= rect.X+rect.Width && X+Width >= rect.X && Y <= rect.Y+rect.Height && Y+Height >= rect.Y)
	{
		return true;
	}
	return false;
}

void Rectangle::SetTexture( sf::Texture & texture )
{
	this->texture=texture;
}
void Rectangle::SetSize(double size)
{
	this->size=size;
	this->Width = texture.getSize().x*size;
	this->Height = texture.getSize().y*size;
	sprite.setScale(size,size);
}

void Rectangle::Draw(sf::RenderWindow & window )
{
	window.draw(sprite);
}

sf::Sprite Rectangle::GetSprite()
{
	return sprite;
}
