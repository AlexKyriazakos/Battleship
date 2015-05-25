#include "CargoShip.h"
#include "Map.h"


void CargoShip::action()
{
	std::vector<Cell*> neighbourCells = map->findNeighbourCells(*this);
}
