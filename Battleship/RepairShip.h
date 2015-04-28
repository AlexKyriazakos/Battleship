#include "Ship.h"

class Map;

class RepairShip : public Ship
{

public:

	RepairShip(Map* map_) : Ship(map_) {}
	//Why virtual again????
	virtual void action()
	{
		//do nothing
	}

	virtual std::string getName(bool extended) const
	{
		if (extended)
			return (std::string("Repair"));
		return(std::string("R"));
	}

	virtual int getType()
	{
		return REPAIR;
	}

};
