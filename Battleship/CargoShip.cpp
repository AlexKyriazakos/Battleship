#include "CargoShip.h"
#include "Map.h"

void CargoShip::action()
{
	std::vector<Cell*> neighbourCells = map->findNeighbourCells(*this);
	for (int i=0; i != neighbourCells.size(); i++)
	{
		if (neighbourCells[i]->hasPort())
			incTreasure(2);
		
	}
	if (map->getCell(location.row, location.col)->hasPort())
			incTreasure(2);
}
