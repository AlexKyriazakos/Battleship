#include "Ship.h"

class Map;

class ExplorerShip : public Ship
{

public:

	ExplorerShip(Map* map_) : Ship(map_) {}
	//Why virtual again????
	virtual void action()
	{
		//do nothing
	}

	virtual std::string getName(bool extended) const
	{
		if (extended)
			return (std::string("Explorer"));
		return(std::string("E"));
	}

	virtual int getType()
	{
		return EXPLORER;
	}

};
