#include "Ship.h"
#include <cstdlib>

int Ship::shipsCreated = 0;
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

void Ship::incHP(double hp_)
{
	currentHp += hp_;
}

void Ship::decHP(double hp_)
{
	currentHp -= hp_;
}

double Ship::getHP() const
{
	return currentHp;
}

int Ship::getSpeed() const
{
	return speed;
}

void Ship::setSpeed(int speed_)
{
	speed = speed_;
}

Ship::Ship()
{
	location.row = 0;
	location.col = 0;
	shipsCreated++;
}

void Ship::incTreasure(double treasure_)
{
	treasure += treasure_;
}

void Ship::decTreasure(double treasure_)
{
	treasure -= treasure_;
}


//Implement Rest