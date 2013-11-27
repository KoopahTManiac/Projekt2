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
	~Rectangle(void);
	bool intersect(Rectangle rect) const;
	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
	void SetX(int X);
	void SetY(int Y);
	void SetWidth(int Width);
	void SetHeight(int Height);
	void SetPos(int X,int Y);
	void SetSize(int Width, int Height);
	void SetTexture(sf::Texture texture);
protected:
	int X,Y,Width,Height;
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif // Rectangle_h__
