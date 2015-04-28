#include "Ship.h"

class Map;

class PirateShip : public Ship
{

public:

	PirateShip(Map* map_) : Ship(map_){}

	//Why virtual again????
	virtual void action()
	{
		//do nothing
	}

	virtual std::string getName(bool extended) const
	{
		if (extended)
			return (std::string("Pirate"));
		return(std::string("P"));
	}

	virtual int getType()
	{
		return PIRATE;
	}

protected:

	double damage;
};

