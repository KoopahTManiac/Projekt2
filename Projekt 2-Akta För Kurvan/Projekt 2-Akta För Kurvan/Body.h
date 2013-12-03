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
	Body(sf::Texture & texture);
	Body::Body(sf::Texture & texture, float X, float Y,sf::Color & color,float size,int width,int height);
	~Body(void);
	void SetTexture( sf::Texture texture );
	void UpdateSprite();
	void SetColor( sf::Color color );
	void TODO();
};

