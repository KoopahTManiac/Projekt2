#ifndef Player_h__
#define Player_h__

#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include "PowerUpp.h"
#include "MyVector.h"
#include "Body.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

using namespace std;
class Player : public Rectangle
{
	static const int SizeOfBodyPartsToStartWith=1000;
	static const int SpawnRateInMilis = (1000/60)*2;
public:
	MyVector<Body> & GetBodyParts();
	Player(void);
	float GetSpeed() const;
	int GetSize() const;
	sf::Keyboard::Key * Keys();
	void Move();
	void RenderBody(sf::RenderWindow & window);
	void ResetBody();
	void SetSize(int val);
	void SetSpeed(float val);
	void SetTexture(sf::Texture texture);
	void SpawnBody();
	void Update(double TimeElapsed);
	void UpdateBuffs();
	void UpdateSprite();
	~Player(void);
	void SetColor(sf::Color color);
private:
	
	MyVector<Body> BodyParts; //My own vector Class MyVector.h and MyVector.cpp 2013-11-26
	double SpawnTimeElapsed;
	int size;
	int AmountOfBodyParts;
	sf::Color color;
	sf::Keyboard::Key pKeys[4]; // keeps track for bound key mapping for each player
	sf::Vector2f Volicity;
	float speed;
	float Rotation;
	bool spawnBodyParts;
};

#endif // Player_h__
