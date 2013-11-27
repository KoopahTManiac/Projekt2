#pragma once
#include "Rectangle.h"
#include <SFML/Graphics.hpp>

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

class Body : public Rectangle
{
public:
	Body(void);
	Body(sf::Texture texture);
	~Body(void);
	void SetTexture( sf::Texture texture );
	void UpdateSprite();
private:

};

