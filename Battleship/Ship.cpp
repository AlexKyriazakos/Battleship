#include "Ship.h"
#include <cstdlib>

//Example implementation, real one has to check neighboring cells
void Ship::move()
{
	int a = rand() % speed; //Create random number 0-speed. modulo operator best
	int b = rand() % speed; // used for int randoms within specified limits

	//problem right here
	//if you dont initialize members like location
	//you are adding to an unknown number.
	location.col += a;
	location.row += b;
}	

void Ship::incHP(int hp_)
{
	currentHp += hp_;
}

int Ship::getHP() const
{
	return currentHp;
}
//Implement Rest