#include "GameManger.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

GameManger::GameManger(void)
{
	TimeElapsed = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	GameState=0;
}

GameManger::~GameManger(void)
{

}

void GameManger::start(sf::RenderWindow &window)
{
	Running = true;
	while(Running)
	{
		window.clear();

		// Update
		Update(window);

		// Draw	
		Draw(window);

		// Display
		window.display();
		Update(window);
	}
	

}

void GameManger::Draw( sf::RenderWindow &window )
{
	switch (GameState)
	{
	case 0:
		{
			//fix gui
			break;
		}
	case 1:
		{
			//Fix Game Drawing
			break;
		}
	}
}

void GameManger::Update(sf::RenderWindow &window)
{
	
	TimeElapsed = clock.getElapsedTime().asMicroseconds();
	SpawnTimeElapsed += clock.getElapsedTime().asMilliseconds();
	clock.restart();
	while(window.pollEvent(event)) 
	{
		switch (event.type) 
		{
		case sf::Event::Closed:
			{
				Running = false;
				window.close();
			}
		}
	}
	switch (GameState)
	{
	case 0:
		{
			//fix gui Update

			break;
		}
	case 1:
		{
			//Fix Game Update
			for (int i = 0; i < amountOffPlayers; i++)
			{
				players[i].Update((double)TimeElapsed/1000);
			}
			break;
		}
	}
	
}