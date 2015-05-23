#include "CargoShip.h"
#include "Map.h"

class Cell;

void CargoShip::action()
{
	std::vector<Cell*> neighbourCells = map->findNeighbourCells(*this);
}
