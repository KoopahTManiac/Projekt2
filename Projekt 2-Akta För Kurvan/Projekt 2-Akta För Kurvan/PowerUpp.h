#ifndef PowerUpp_h__
#define PowerUpp_h__

#include "Rectangle.h"
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
	~PowerUpp();
	int GetDuration() const;
	int GetType() const;
	void SetDuration(int val);
	void SetType(int val);
protected:
	int type;
	int duration;

};
#endif // PowerUpp_h__

