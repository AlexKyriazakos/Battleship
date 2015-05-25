#ifndef GUARD_ExplorerShip_h
#define GUARD_ExplorerShip_h

#include "Ship.h"

class Map;

class ExplorerShip : public Ship
{

public:

	ExplorerShip(Map* map_) : Ship(map_) {}

	virtual void action();

	virtual std::string getName(bool extended) const
	{
		if (extended)
			return (std::string("Explorer"));
		return(std::string("E"));
	}

	virtual int getType() const
	{
		return EXPLORER;
	}

};
#endif