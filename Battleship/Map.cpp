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

std::vector<Cell*> Map::findFullCells(Ship& ship)
{
	std::vector<Cell*> fullCells;
	Coords loc(ship.getLocation());
	for (int i = loc.row - 1; i <= loc.row + 1; ++i)
	{
		for (int j = loc.col - 1; j <= loc.col + 1; ++j)
		{
			if (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() && (!(i == loc.row && j == loc.col)))
			{
				if (grid[i][j].hasShip())
						fullCells.push_back(&grid[i][j]);
			}
		}
	}
	return fullCells;
}

std::vector<Cell*> Map::findNeighbourCells(Ship& ship)
{
	std::vector<Cell*> NeighbourCells;
	Coords loc(ship.getLocation());
	for (int i = loc.row - 1; i <= loc.row + 1; ++i)
	{
		for (int j = loc.col - 1; j <= loc.col + 1; ++j)
		{
			if (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() && (!(i == loc.row && j == loc.col)))
			{
				NeighbourCells.push_back(&grid[i][j]);
			}
		}
	}
	return NeighbourCells;
}

Cell* Map::getCell(int row, int col)
{
	return &grid[row][col];
}


void Map::moveShips()
{
	Ship* cur;
	std::ofstream myfile;
	myfile.open("Move2.txt", std::ios::out);
	for (std::list<Ship*>::iterator it = ships.begin(); it != ships.end(); ++it)
	{
		cur = *it;
		for (int s = 0; s != cur->getSpeed(); s++)
		{
			Coords currentposition(cur->getLocation());
			//find the empty cells around this ship
			std::vector<Cell*> neighbours = findEmptyCells(*cur);

			//pick a random cell from the empty ones
			int r = rand() % neighbours.size();

			//Remove the ship from its previous cell
			grid[currentposition.row][currentposition.col].removeShip();

			//Move the ship to its new cell
			cur->setLocation(neighbours[r]->getCoords());
			Coords newposition(cur->getLocation());
			grid[newposition.row][newposition.col].setShip(cur);
			myfile << *cur;
			myfile << "[" << currentposition.row << "," << currentposition.col << "] -> "
				<< "[" << newposition.row << "," << newposition.col << "]" << std::endl;
		}
		myfile << std::endl;
	}
	myfile.close();
	
}

void Map::actionShips()
{
	Ship* cur;
	std::ofstream myfile;
	myfile.open("Move3.txt", std::ios::out);
	for (std::list<Ship*>::iterator it = ships.begin(); it != ships.end(); ++it)
	{
		cur = *it;
		//Coords currentposition(ships[i]->getLocation());
		//myfile << ships[i]->getName(1) << "\t\t";
		//myfile << "[" << currentposition.row << "," << currentposition.col << "] -> ";
		myfile << *cur;
		cur->action();
		myfile << *cur << std::endl;
		//currentposition=ships[i]->getLocation();
		//myfile << "[" << currentposition.row << "," << currentposition.col << "]" << std::endl;

	}
}


void Map::placeShips()
{
	int i = 0;
	Ship* cur;
	for (std::list<Ship*>::iterator it = ships.begin(); it != ships.end(); ++it)
	{
		int x, y, t;
		t = rand() % 4;
		cur = *it;
		if (t == 0)
		{
			cur = new PirateShip(this);
		}
		else if (t == 1)
		{
			cur = new CargoShip(this);
		}
		else if (t == 2)
		{
			cur = new RepairShip(this);
		}
		else if (t == 3)
		{
			cur = new ExplorerShip(this);
		}
		do
		{
			x = rand() % grid.size();
			y = rand() % grid.size();
		} while (grid[x][y].hasShip());
		grid[x][y].setShip(*it);
		cur->setLocation(x, y);
		cur->number = i;
		++i;
		std::cout << cur->getName(true) << std::endl;
		
	}
}

void Map::placePorts(double portPercent)
{
	if (portPercent <= 1)
	{
		for (int i = 0; i != int(portPercent*GRIDSIZE*GRIDSIZE); ++i)
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
}

void Map::placeTreasure(double treasurePercent)
{
	if (treasurePercent <= 1)
	{
		for (int i = 0; i != int(treasurePercent*GRIDSIZE*GRIDSIZE); ++i)
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
}

void Map::checkWeather()
{
	Ship* cur;
	for (std::list<Ship*>::iterator it = ships.begin(); it != ships.end(); ++it)
	{
		cur = *it;
		Coords currentposition(cur->getLocation());
		if (grid[currentposition.row][currentposition.col].getWeather() > 6)
			cur->decHP(20);
	}
}

void Map::checkTreasure()
{
	Ship* cur;
	for (std::list<Ship*>::iterator it = ships.begin(); it != ships.end(); ++it)
	{
		cur = *it;
		Coords currentposition(cur->getLocation());
		if (grid[currentposition.row][currentposition.col].hasTreasure())
		{
			cur->incTreasure(1);
		}

	}
}

void Map::checkPort()
{
	Ship* cur;
	for (std::list<Ship*>::iterator it = ships.begin(); it != ships.end(); ++it)
	{
		cur = *it;
		Coords currentPosition(cur->getLocation());
		if (getCell(currentPosition.row, currentPosition.col)->hasPort())
		{
			if (cur->getType() != 0)
				cur->incHP(20);
			else
				cur->decHP(15);
		}
		if (cur->getType() == 0)
		{
			std::vector<Cell*> neighbourCells = findNeighbourCells(*cur);
			for (int j = 0; j != neighbourCells.size(); ++j)
			{
				if (neighbourCells[j]->hasPort())
					cur->decHP(15);
			}
		}
	}
}


int Map::deadShips()
{
	Ship* cur;
	for (std::list<Ship*>::iterator it = ships.begin(); it != ships.end(); ++it)
	{
		cur = *it;
		if ((cur->getHP()) <= 0)
		{
			Coords currentPosition(cur->getLocation());
			grid[currentPosition.row][currentPosition.col].removeShip();
			ships.erase(it);
		}
		
	}
	if (ships.size() == 0)
		return 1;
	else
		return 0;
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


void Map::printInfo()
{
	std::cout << "          SHIPS" << std::endl;
	for (int i = 0; i != GRIDSIZE + 2; ++i)
	{
		if (i == 0)
			std::cout << "  |0|1|2|3|4|5|6|7|8|9|" << std::endl;
		if (i == 1)
			std::cout << "-----------------------" << std::endl;
		if (i > 1)
		{
			std::cout << i - 2 << " |";
			for (int j = 0; j != GRIDSIZE; ++j)
			{
				if (grid[i - 2][j].getShip())
					std::cout << grid[i - 2][j].getShip()->getName(false) << "|";
				else
					std::cout << " |";
			}
			std::cout << std::endl;
		}

	}
	std::cout << "        WEATHER" << std::endl;
	for (int i = 0; i != GRIDSIZE + 2; ++i)
	{
		if (i == 0)
			std::cout << "  |0|1|2|3|4|5|6|7|8|9|" << std::endl;
		if (i == 1)
			std::cout << "-----------------------" << std::endl;
		if (i > 1)
		{
			std::cout << i - 2 << " |";
			for (int j = 0; j != GRIDSIZE; ++j)
			{
				std::cout << grid[i - 2][j].getWeather() - 1 << "|";
			}
			std::cout << std::endl;
		}

	}

	std::cout << "          PORTS" << std::endl;
	for (int i = 0; i != GRIDSIZE + 2; ++i)
	{
		if (i == 0)
			std::cout << "  |0|1|2|3|4|5|6|7|8|9|" << std::endl;
		if (i == 1)
			std::cout << "-----------------------" << std::endl;
		if (i > 1)
		{
			std::cout << i - 2 << " |";
			for (int j = 0; j != GRIDSIZE; ++j)
			{
				if (grid[i - 2][j].hasPort())
					std::cout << "P|";
				else
					std::cout << " |";
			}
			std::cout << std::endl;
		}

	}

	std::cout << "        TREASURE" << std::endl;
	for (int i = 0; i != GRIDSIZE + 2; ++i)
	{
		if (i == 0)
			std::cout << "  |0|1|2|3|4|5|6|7|8|9|" << std::endl;
		if (i == 1)
			std::cout << "-----------------------" << std::endl;
		if (i > 1)
		{
			std::cout << i - 2 << " |";
			for (int j = 0; j != GRIDSIZE; ++j)
			{
				if (grid[i - 2][j].hasTreasure())
					std::cout << "T|";
				else
					std::cout << " |";
			}
			std::cout << std::endl;
		}

	}
}







Map::~Map()
{
	Ship* cur;
	for (std::list<Ship*>::iterator it = ships.begin(); it != ships.end(); ++it)
	{
		cur = *it;
		delete (cur);
	}
	ships.clear();
}


