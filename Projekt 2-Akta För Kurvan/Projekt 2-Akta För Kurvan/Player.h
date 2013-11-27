#ifndef Player_h__
#define Player_h__

#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include "PowerUpp.h"
#include "MyVector.h"
#include "Body.h"
//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

using namespace std;
class Player : public Rectangle
{
public:
	Player(void);
	~Player(void);
	void Move();
	void Update(double TimeElapsed);
	int GetSize() const;
	void SetSize(int val);
	double GetSpeed() const;
	void SetSpeed(double val);
	void UpdateBuffs();
	void SetTexture(sf::Texture texture);
	void UpdateSprite();
private:
	int size;
	double speed;
	sf::Keyboard::Key pKeys[4]; // keeps track for bound key mapping for each player
	MyVector<Body> BodyParts;     //My own vector Class MyVector.h and MyVector.cpp 2013-11-26
};

#endif // Player_h__
