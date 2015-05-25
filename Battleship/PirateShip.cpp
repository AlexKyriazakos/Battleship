#include "PirateShip.h"
#include "Map.h"


void PirateShip::action()
{
	std::vector<Cell*> fullCells = map->findFullCells(*this);
	if (fullCells.size() > 0)
	{
		int r = rand() % fullCells.size();
		fullCells[r]->getShip()->decHP(30);
		double loot(fullCells[r]->getShip()->getTreasure() / 2);
		fullCells[r]->getShip()->decTreasure(loot);
		incTreasure(loot);
	}

}

double PirateShip::getDamage()
{
	return damage;
}
