#include "ExplorerShip.h"
#include "Map.h"


void ExplorerShip::action()
{
	std::vector<Cell*> fullCells = map->findFullCells(*this);
	for (int i = 0; i != fullCells.size(); i++)
	{

		if ((fullCells[i]->getShip()->getType()) == 0)
		{
			Coords enemyCell = fullCells[i]->getCoords();
			Coords newLoc(location);
			newLoc.row += -(enemyCell.row - location.row);
			newLoc.col += -(enemyCell.col - location.col);
			if (newLoc.row >= 0 && newLoc.row < map->grid.size() && newLoc.col >= 0 && newLoc.col < map->grid.size())
			{
				if (!map->grid[newLoc.row][newLoc.col].hasShip())
				{
					map->grid[location.row][location.col].removeShip();
					setLocation(newLoc);
					map->grid[newLoc.row][newLoc.col].setShip(this);
					
					return;
				}
			}
		}
		
	}	


	std::vector<Cell*> neighbourCells = map->findNeighbourCells(*this);
	for (int i = 0; i != neighbourCells.size(); i++)
	{
		
		if (neighbourCells[i]->getWeather() > 6)
		{
			Coords enemyCell = neighbourCells[i]->getCoords();
			Coords newLoc(location);
			newLoc.row += -(enemyCell.row - location.row);
			newLoc.col += -(enemyCell.col - location.col);
			if (newLoc.row >= 0 && newLoc.row < map->grid.size() && newLoc.col >= 0 && newLoc.col < map->grid.size())
			{
				if (!map->grid[newLoc.row][newLoc.col].hasShip())
				{
					map->grid[location.row][location.col].removeShip();
					setLocation(newLoc);
					map->grid[newLoc.row][newLoc.col].setShip(this);
					
					return;
				}
			}
		}
		
			
	}

}