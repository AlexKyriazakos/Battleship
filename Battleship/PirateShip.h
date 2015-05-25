#ifndef GUARD_PirateShip_h
#define GUARD_PirateShip_h


#include "Ship.h"

class Map;

class PirateShip : public Ship
{

public:

	PirateShip(Map* map_) : Ship(map_)
	{
		damage = 20;
		speed = 1;
	}

	//Why virtual again????
	virtual void action();

	virtual std::string getName(bool extended) const
	{
		if (extended)
			return (std::string("Pirate"));
		return(std::string("P"));
	}

	virtual int getType() const
	{
		return PIRATE;
	}

	double getDamage();

protected:

		double damage;
};

#endif
