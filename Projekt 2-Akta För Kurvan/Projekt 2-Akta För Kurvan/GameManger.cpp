#include "GameManger.h"
#include "PowerUpp.h"



//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////

GameManger::GameManger(void)
{
	correntPlayerSelected =0;
	TimeElapsed = clock.getElapsedTime().asMicroseconds();
	gameBounds.SetWidth(800);
	gameBounds.SetHeight(600);
	gameBounds.SetPos(0,0);
	amountOffPlayers = 2;
	amountOffPlayersAlive = 2;
	clock.restart();
	GameState=0;
	StartTimeElapsed = 0;
	SpawnTimeElapsed = 0;
	AmountOfPowerUpps = 2;
	spawnTimeNeaded = 4000;
	amountOffRounds =0;
	GoalOffRounds = 5;
	amountOffPlayersWithSameStats =0;
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
	stringstream titleBuilder;
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
				titleBuilder << "Score Player"<< i+1 << ": " << players[i].Score() << "  ";
				
			}
			window.setTitle(titleBuilder.str());
			for (int i=0; i < powerUpps.Size(); i++)
			{
				powerUpps.At(i).DrawBuff(window);
			}
			break;
		}
	}
}

void GameManger::Update(sf::RenderWindow &window)
{
	int maxscore = 0;
	TimeElapsed = clock.getElapsedTime().asMicroseconds();
	StartTimeElapsed += clock.getElapsedTime().asMilliseconds();
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
			players[1].Keys()[0] = Keyboard::A;
			players[1].Keys()[1] = Keyboard::S;
			GameState = 1;
			GameActive = true;

			for (int i=0; i < amountOffPlayers;i++)
			{
				switch (i)
				{
				case 0:
					players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Red);
					break;
				case 1:
					players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Green);
					break;
				case 2:
					players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Blue);
					break;
				case 3:
					players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Yellow);
					break;
				case 4:
					players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Magenta);
					break;
				}
			}
			break;
		}
	case 1:
		{
			
			StartTimeElapsed += (Int32)TimeElapsed;
			if (GameActive)
			{
				if (StartTimeElapsed/1000 > ROUNDDELAYINMS) // time till start of round
				{
					SpawnTimeElapsed += (Int32)TimeElapsed;
					if (SpawnTimeElapsed/1000 > spawnTimeNeaded)
					{
						PowerUpp tempPowerUpp;
						tempPowerUpp.SetPos(float(rand()%(gameBounds.GetWidth()-100)+50),float(rand()%(gameBounds.GetHeight()-100)+50));
						tempPowerUpp.SetType(rand()%AmountOfPowerUpps);
						powerUpps.push_back(tempPowerUpp);
						SpawnTimeElapsed = 0;
						spawnTimeNeaded = rand()&2700+3000;
					}
					//Fix Game Update
					for (int i = 0; i < amountOffPlayers; i++)
					{
						players[i].Update((Int32)(TimeElapsed/1000));
						for (int t=0; t < powerUpps.Size();t++)
						{
							if(players[i].intersect(powerUpps.At(t)) && !powerUpps.At(t).GetActive())
							{
								powerUpps.At(t).SetOwner(players,i,amountOffPlayers);
								powerUpps.At(t).SetActive(true);
								powerUpps.At(t).ApplyBuff(players,i,amountOffPlayers);
							}
						}
						for (int t = 0; t < amountOffPlayers; t++)
						{
							if (i == t)
							{
								if ((players[i].IsAlive() && players[i].intersectToOwnBody() || (players[i].IsAlive() && players[i].intersectWall(gameBounds))))
								{
									amountOffPlayersAlive--;
									if (amountOffPlayersAlive <2)
									{
										GameActive = false;
									}
									AddScoreToAlivePlayers();
								}
							}
							else if ((players[i].IsAlive() && players[i].intersectToBody(players[t])) || (players[i].IsAlive() && players[i].intersectWall(gameBounds)))
							{
								amountOffPlayersAlive--;
								if (amountOffPlayersAlive <2)
								{
									GameActive = false;
								}
								AddScoreToAlivePlayers();
							}
						}
						
					}
					for (int i=0; i < powerUpps.Size(); i++)
					{
						if(powerUpps.At(i).UpdateBuff((float)TimeElapsed/1000))
						{
							powerUpps.erase(i);
						}
					}
					
				}
			}
			else
			{
				if (Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					powerUpps.ResetVector();
					amountOffRounds++;
					for (int i = 0; i < amountOffPlayers; i++)
					{
						if (maxscore < players[i].GetScore())
						{
							maxscore = players[i].GetScore();
							amountOffPlayersWithSameStats = 1;
						}
						else if (maxscore == players[i].GetScore())
						{
							amountOffPlayersWithSameStats++;
						}
					}
					if (amountOffRounds < GoalOffRounds || amountOffPlayersWithSameStats >1)
					{
						GameActive = true;
						amountOffPlayersAlive = amountOffPlayers;
						
						for (int i=0; i < amountOffPlayers;i++)
						{
							switch (i)
							{
							case 0:
								players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Red);
								break;
							case 1:
								players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Green);
								break;
							case 2:
								players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Blue);
								break;
							case 3:
								players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Yellow);
								break;
							case 4:
								players[i].SemiResetPlayer(float(rand()%550+150),float(rand()%350+150),Color::Magenta);
								break;
							}
						}
					}
					else
					{

					}
				}
			}
			break;
		}
	}
}

void GameManger::AddScoreToAlivePlayers()
{
	for (int i = 0; i < amountOffPlayers; i++)
	{
		if (players[i].IsAlive())
		{
			players[i].AddScore();
		}
	}
}
