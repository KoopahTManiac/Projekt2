#ifndef Player_h__
#define Player_h__

#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include "MyVector.h"
#include "Body.h"
#include <vector>
#include <cstdlib>
#include <ctime>

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

using namespace std;
class Player : public Rectangle
{
public:
	MyVector<Body> & GetBodyParts();
	Player(void);
	~Player(void);
	bool IsAlive() const;
	bool intersectToBody(Player & player);
	float GetSpeed() const;
	float GetSize() const;
	int Score() const;
	sf::Keyboard::Key * Keys();
	void IsAlive(bool val);
	void Move();
	void RenderBody(sf::RenderWindow & window);
	void ResetBody();
	void Score(int val);
	void SetColor(sf::Color color);
	void SetSize(float val);
	void SetSpeed(float val);
	void SetTexture(sf::Texture texture);
	void SpawnBody();
	void SpawnBody(float x,float y);
	void Update(double TimeElapsed);
	void UpdateBuffs();
	void UpdateSprite();
	void AddScore();
	bool intersectWall( Rectangle & gameBounds );
	void SetRotationSpeed( float rot );
	float GetRotationSpeed();
	void ResetPlayer(float X, float Y,sf::Color color);
	void SemiResetPlayer(float X,float Y,sf::Color color);
	bool intersectToOwnBody();
	int GetScore();
private:
	MyVector<Body> BodyParts; //My own vector Class MyVector.h and MyVector.cpp 2013-11-26
	bool alive;
	bool canMoveHead;
	bool spawnBodyParts;
	double SpawnTimeElapsed;
	float Rotation;
	float speed;
	int AmountOfBodyParts;
	int score;
	float size;
	sf::Color color;
	sf::Keyboard::Key pKeys[2]; // keeps track for bound key mapping for each player
	sf::Vector2f Volicity;
	float SpawnRateInMilis;
	float RotationSpeed;
	int spawnsToBeMade;
	int startHole,endHole;
	Body tempBody;
	bool canColide;
	bool powerUppColideActive;

};

#endif // Player_h__
