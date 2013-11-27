#include "Rectangle.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////


Rectangle::Rectangle(void)
{
}


Rectangle::~Rectangle(void)
{

}

int Rectangle::GetX() const
{
	return X;
}

int Rectangle::GetY() const
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

void Rectangle::SetX( int X )
{
	this->X = X;
}

void Rectangle::SetY( int Y )
{
	this->Y= Y;
}

void Rectangle::SetWidth( int Width )
{
	this->Width=Width;
}

void Rectangle::SetHeight( int Height )
{
	this->Height=Height;
}

void Rectangle::SetPos( int X,int Y )
{
	this->X=X;
	this->Y=Y;
}

void Rectangle::SetSize( int Width, int Height )
{
	this->Width = Width;
	this->Height = Height;
}

bool Rectangle::intersect( Rectangle rect ) const
{
	if (X <= rect.X+rect.Width && X+Width >= rect.X && Y <= rect.Y+rect.Height && Y+Height >= rect.Y)
	{
		return true;
	}
	return false;
}

void Rectangle::SetTexture( sf::Texture texture )
{
	this->texture=texture;
}

