#include "Ship.h"

class Map;

class CargoShip : public Ship
{

public:

	CargoShip(Map* map_) : Ship(map_){}
	//Why virtual again????
	virtual void action()
	{
		std::vector<Cell*> NeighbourCells;
		for (int i = location.row - 1; i <= location.row + 1; ++i)
		{
			for (int j = location.col - 1; j <= location.col + 1; ++j)
			{
				if (i >= 0 && i < 12 && j >= 0 && j < 12)
				{
					NeighbourCells.push_back(map->getCell(i, j));
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
