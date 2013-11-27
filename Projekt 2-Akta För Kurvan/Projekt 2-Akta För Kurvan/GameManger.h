#ifndef GameManger_h__
#define GameManger_h__

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////


#include <SFML\Graphics.hpp>
#include "Player.h"
#include "SFML\System.hpp"
using namespace sf;
using namespace std;
class GameManger
{
	static const int MAX_PLAYERS = 5;
public:
	GameManger(void);
	~GameManger(void);
	void start(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
private:
	Player players[MAX_PLAYERS];
	MyVector<PowerUpp> powerUpps;
	int amountOffPlayers;
	sf::Int64 TimeElapsed;
	sf::Clock clock;
	sf::Event event;
	sf::Int32 SpawnTimeElapsed;
	bool Running;
	int GameState;
	sf::Keyboard::Key LastKeyDown;
};

#endif // GameManger_h__
