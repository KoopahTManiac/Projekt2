#include "GameManger.h"

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

GameManger::GameManger(void)
{
	TimeElapsed = clock.getElapsedTime().asMicroseconds();
	amountOffPlayers = 2;
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
		this->Draw(window);

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
			for (int i = 0; i < amountOffPlayers; i++)
			{
				players[i].RenderBody(window);
				players[i].Draw(window);
			}
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
			players[0].Keys()[0] = Keyboard::Left;
			players[0].Keys()[1] = Keyboard::Right;
			players[0].SetColor(sf::Color::White);
			players[0].SetPos(200,200);
			players[1].Keys()[0] = Keyboard::A;
			players[1].Keys()[1] = Keyboard::S;
			
			GameState = 1;
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