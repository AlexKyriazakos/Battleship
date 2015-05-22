#include "Ship.h"

class Map;

class CargoShip : public Ship
{

public:

	CargoShip(Map* map_) : Ship(map_){}
	//Why virtual again????
	virtual void action()
	{
		for (int i = location.row - 1; i <= location.row + 1; ++i)
		{
			for (int j = location.col - 1; j <= location.col + 1; ++j)
			{
				if (i >= 0 && i < map->grid.size() && j >= 0 && j < map->grid.size())
				{
					if (map->grid[i][j].hasPort())
						treasure++;
				}
			}
		}
			

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
