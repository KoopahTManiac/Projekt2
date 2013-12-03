#ifndef PowerUpp_h__
#define PowerUpp_h__

#include "Rectangle.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
//////////////////////////////////////////////////////////////////////////
//						Made By Zoran Ostojic Zoos13					//
//								2013-11-26								//
//////////////////////////////////////////////////////////////////////////
using namespace std;

class PowerUpp : public Rectangle
{
public:
	PowerUpp();
	PowerUpp(PowerUpp &powerUpp);
	PowerUpp( float X, float Y , int type);
	~PowerUpp();
	Player GetOwner() const;
	bool UpdateBuff( float TimeElapsed);
	float GetDuration() const;
	void ApplyBuff( Player * player , int corrent, int size);
	void UnApplyBuff(Player * player , int corrent, int size);
	void SetOwner(Player * player , int corrent, int size);
	void SetActive(bool active);
	void SetDuration(float val);
	void DrawBuff(sf::RenderWindow & window);
	void SetType(int type);
	int GetType();
	bool GetActive();
protected:
	float duration;
	Player *owner;
	bool active;
	int type;
	int corrent;
	int sizeOfPlayers;
};
#endif // PowerUpp_h__

