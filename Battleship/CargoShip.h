#include "Ship.h"

class Map;

class CargoShip : public Ship
{

public:

	CargoShip(Map* map_) : Ship(map_){}
	//Why virtual again????
	virtual void action()
	{
		//do nothing
	}

	virtual std::string getName(bool extended) const
	{
		if (extended)
			return (std::string("Cargo"));
		return(std::string("C"));
	}

	virtual int getType()
	{
		return CARGO;
	}

};
