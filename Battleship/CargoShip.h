#ifndef GUARD_CargoShip_h
#define GUARD_CargoShip_h

#include "Ship.h"

class CargoShip : public Ship
{

public:

	CargoShip(Map* map_) : Ship(map_){}
	//Why virtual again????
	virtual void action();

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
#endif // GUARD_CargoShip_h
