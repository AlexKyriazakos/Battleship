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
			myfile << *ships[i];
			myfile << "[" << currentposition.row << "," << currentposition.col << "] -> "
				<< "[" << newposition.row << "," << newposition.col << "]" << std::endl;
		}
		myfile << std::endl;
	}
	myfile.close();
	
}

void Map::actionShips()
{
	std::ofstream myfile;
	myfile.open("Move3.txt", std::ios::out);
	for (int i = 0; i != ships.size(); i++)
	{
		//Coords currentposition(ships[i]->getLocation());
		//myfile << ships[i]->getName(1) << "\t\t";
		//myfile << "[" << currentposition.row << "," << currentposition.col << "] -> ";
		myfile << *ships[i];
		ships[i]->action();
		myfile << *ships[i] << std::endl;
		//currentposition=ships[i]->getLocation();
		//myfile << "[" << currentposition.row << "," << currentposition.col << "]" << std::endl;

	}
}


void Map::placeShips()
{
	for (int i = 0; i != ships.size(); i++)
	{
		int x, y, t;
		t = rand() % 4;
		if (t == 0)
		{
			ships[i] = new PirateShip(this);
		}
		else if (t == 1)
		{
			ships[i] = new CargoShip(this);
		}
		else if (t == 2)
		{
			ships[i] = new RepairShip(this);
		}
		else if (t == 3)
		{
			ships[i] = new ExplorerShip(this);
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
	for (int i = 0; i != ships.size(); i++)
	{
		Coords currentposition(ships[i]->getLocation());
		if (grid[currentposition.row][currentposition.col].getWeather() > 6)
			ships[i]->decHP(20);
	}
}

void Map::checkTreasure()
{
	for (int i = 0; i != ships.size(); i++)
	{
		Coords currentposition(ships[i]->getLocation());
		if (grid[currentposition.row][currentposition.col].hasTreasure())
		{
			ships[i]->incTreasure(1);
		}

	}
}

void Map::checkPort()
{
	for (int i = 0; i != ships.size(); ++i)
	{
		Coords currentPosition(ships[i]->getLocation());
		if (getCell(currentPosition.row, currentPosition.col)->hasPort())
		{
			if (ships[i]->getType() != 0)
				ships[i]->incHP(20);
			else
				ships[i]->decHP(15);
		}
		if (ships[i]->getType() == 0)
		{
			std::vector<Cell*> neighbourCells = findNeighbourCells(*ships[i]);
			for (int j = 0; j != neighbourCells.size(); ++j)
			{
				if (neighbourCells[j]->hasPort())
					ships[i]->decHP(15);
			}
		}
	}
}


int Map::deadShips()
{
	for (int i = 0; i != ships.size(); ++i)
	{
		if (ships[i]->getHP() <= 0)
		{
			Coords currentPosition(ships[i]->getLocation());
			grid[currentPosition.row][currentPosition.col].removeShip();
			ships.erase(ships.begin() + i);
			i--;
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
	for (int i = 0; i != ships.size(); i++)
		delete (ships[i]);
	ships.clear();
}


