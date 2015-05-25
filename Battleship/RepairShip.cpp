#include "RepairShip.h"
#include "Map.h"


void RepairShip::action()
{
	std::vector<Cell*> fullCells = map->findFullCells(*this);
	for (int i = 0; i != fullCells.size(); ++i)
	{
		if (fullCells[i]->getShip()->getTreasure() >= 1)
		{
			fullCells[i]->getShip()->incHP(30);
			fullCells[i]->getShip()->decTreasure(1);
			incTreasure(1);
		}
	}
	
}