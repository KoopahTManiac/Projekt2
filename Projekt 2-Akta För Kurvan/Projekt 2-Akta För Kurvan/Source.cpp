#include<SFML\Graphics.hpp>
#include"GameManger.h"
using namespace sf;

//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////


int main ()
{
	
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(800,600),"Akta För Kurvan");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	
	GameManger manager;

	manager.start(window);
}