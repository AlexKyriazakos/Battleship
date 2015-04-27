#include <iostream>
#include <fstream>


#include "Map.h"



std::vector<Cell*> Map::findEmptyCells(Ship& ship)
{
	std::vector<Cell*> emptyCells;
	Coords loc(ship.getLocation());
	for (int i = loc.row - 1; i <= loc.row + 1; ++i)
	{
		for (int j = loc.col - 1; j <= loc.col + 1; ++j)
		{
			if (i >= 0 && i < grid.size() && j >= 0 && j < grid.size())
			{
				if (!grid[i][j].hasShip())
					emptyCells.push_back(&grid[i][j]);
			}
		}
	}
	return emptyCells;
}



void Map::moveShips()
{
	std::ofstream myfile;
	myfile.open("Move2.txt", std::ios::out);
	for (int i = 0; i != ships.size(); i++)
	{
		for (int s = 0; s != ships[i]->getSpeed(); s++)
		{
			Coords currentposition(ships[i]->getLocation());
			//find the empty cells around this ship
			std::vector<Cell*> neighbours = findEmptyCells(*ships[i]);

			//pick a random cell from the empty ones
			int r = rand() % neighbours.size();

			//Remove the ship from its previous cell
			grid[currentposition.row][currentposition.col].removeShip();

			//Move the ship to its new cell
			ships[i]->setLocation(neighbours[r]->getCoords());
			Coords newposition(ships[i]->getLocation());
			grid[newposition.row][newposition.col].setShip(ships[i]);
			//myfile << *ships[i];
			myfile << "[" << currentposition.row << "," << currentposition.col << "] -> "
				<< "[" << newposition.row << "," << newposition.col << "]" << std::endl;
		}
		myfile << std::endl;
	}
	myfile.close();
	
}


void Map::placeShips()
{
	for (int i = 0; i != ships.size(); i++)
	{
		int x, y, t;
		t = rand() % 4;
		if (t == 0)
		{
			ships[i] = new PirateShip;
			ships[i]->setSpeed(1);
		}
		else if (t == 1)
		{
			ships[i] = new CargoShip;
		}
		else if (t == 2)
		{
			ships[i] = new RepairShip;
		}
		else if (t == 3)
		{
			ships[i] = new ExplorerShip;
		}
		do
		{
			x = rand() % grid.size();
			y = rand() % grid.size();
		} while (grid[x][y].hasShip());
		grid[x][y].setShip(ships[i]);
		ships[i]->setLocation(x, y);
		ships[i]->number = i;
	}
}

void Map::placePorts()
{
	for (int i = 0; i != int(PORT*GRIDSIZE*GRIDSIZE); ++i)
	{
		int x, y;
		do
		{
			x = rand() % grid.size();
			y = rand() % grid.size();
		} while (grid[x][y].hasPort());
		grid[x][y].setPort(true);
	}
}

void Map::placeTreasure()
{
	for (int i = 0; i != int(TREASURE*GRIDSIZE*GRIDSIZE); ++i)
	{
		int x, y;
		do
		{
			x = rand() % grid.size();
			y = rand() % grid.size();
		} while (grid[x][y].hasTreasure());
		grid[x][y].setTreasure(true);
	}
}

void Map::initCoords()
{
	for (int i = 0; i != grid.size(); ++i)
	{
		for (int j = 0; j != grid.size(); ++j)
		{
			grid[i][j].setCoords(Coords(i, j));
			grid[i][j].setWeather((rand() % 10) + 1);
		}
	}
}