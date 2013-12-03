#ifndef GameManger_h__
#define GameManger_h__

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////


#include <SFML\Graphics.hpp>
#include "Player.h"
#include "SFML\System.hpp"
#include <sstream>
#include "PowerUpp.h"
using namespace sf;
using namespace std;
class GameManger
{
	static const int MAX_PLAYERS = 5;
	static const int ROUNDDELAYINMS = 3000;
public:
	GameManger(void);
	~GameManger(void);
	void start(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	void AddScoreToAlivePlayers();
private:
	MyVector<PowerUpp> powerUpps;
	Player players[MAX_PLAYERS];
	bool Running;
	int GameState;
	int amountOffPlayers;
	sf::Clock clock;
	sf::Event event;
	sf::Int32 StartTimeElapsed;
	sf::Int64 TimeElapsed;
	sf::Keyboard::Key LastKeyDown;
	int amountOffPlayersAlive;
	Rectangle gameBounds;
	PowerUpp tempPowerUpp;
	sf::Int32 spawnTimeNeaded;
	sf::Int32 SpawnTimeElapsed;
	int AmountOfPowerUpps;
	bool GameActive;
	int amountOffRounds;
	int GoalOffRounds;
	int amountOffPlayersWithSameStats;
	int correntPlayerSelected;
};

#endif // GameManger_h__
