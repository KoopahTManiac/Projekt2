#ifndef Rectangle_h__
#define Rectangle_h__
#include "SFML\Graphics.hpp"
//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

using namespace std;
class Rectangle
{
public:
	Rectangle(void);
	bool intersect(Rectangle & rect) const;
	int GetHeight() const;
	int GetWidth() const;
	float GetX() const;
	float GetY() const;
	sf::Sprite GetSprite();
	void Draw(sf::RenderWindow & window );
	void SetHeight(int Height);
	void SetPos(float X,float Y);
	void SetSize(double size);
	void SetSize(int Width, int Height);
	void SetTexture(sf::Texture & texture);
	void SetWidth(int Width);
	void SetX(float X);
	void SetY(float Y);
	~Rectangle(void);
protected:
	float X,Y;
	int Width,Height;
	float size;
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif // Rectangle_h__
