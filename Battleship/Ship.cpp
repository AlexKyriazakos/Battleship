#include "Ship.h"
#include "Definitions.h"
#include <cstdlib>

int Ship::shipsCreated = 0;
//Example implementation, real one has to check neighboring cells
void Ship::move()
{
	for (int i = 0; i != speed; ++i)
	{
		int d;
		//pick a direction
		d = rand() % 2;

		if (d == 0)
			Ship::location.row == GRIDSIZE-1 ? Ship::location.row -= 1 : Ship::location.row += 1;
		if (d == 1)
			Ship::location.col == GRIDSIZE-1 ? Ship::location.col -= 1 : Ship::location.col += 1;
	}

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
	speed = 2;
	maxHp = 100;
	currentHp = maxHp;
	treasure = 0;
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

void Ship::setLocation(Coords location_)
{
	location = location_;
}

void Ship::setLocation(int x_, int y_)
{
	location.row = x_;
	location.col = y_;
}

int Ship::getTreasure() const
{
	return treasure;
}

Coords Ship::getLocation() const
{
	return location;
}




std::ostream& operator<<(std::ostream& os, const Ship& ship)
{
	os << ship.getName(true) << " Ship" << std::endl;
	os << "-Speed    :" << ship.getSpeed() << std::endl;
	os << "-HP       :" << ship.getHP() << std::endl;
	os << "-Treasure :" << ship.getTreasure() << std::endl;
	os << "-Location :[" << ship.location.row << "," << ship.location.col << "]" << std::endl;
	os << "-Number   :" << ship.number << std::endl;
	return os;
}

//Implement Rest