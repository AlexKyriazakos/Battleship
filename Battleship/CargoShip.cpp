#include "CargoShip.h"
#include "Map.h"

<<<<<<< HEAD
=======

>>>>>>> 31d37860ffd8c1d3fadf1d237dc9e3b4bef94b28

void CargoShip::action()
{
	std::vector<Cell*> neighbourCells = map->findNeighbourCells(*this);
	for (int i=0; i != neighbourCells.size(); i++)
	{
		if (neighbourCells[i]->hasPort())
			treasure++;
	}
}
