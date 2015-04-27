#include <iostream>
#include <fstream>

#include "Cell.h"
#include "Definitions.h"
#include "Map.h"

#define echo(x) std::cout<<#x<<" = "<<x<<std::endl


std::vector< std::vector< Cell> > grid(GRIDSIZE, std::vector<Cell>(GRIDSIZE));



std::vector<Cell*> findEmptyCells(Ship& ship)
{
	std::vector<Cell*> emptyCells;
	Coords loc(ship.getLocation());
	for (int i = loc.row - 1; i <= loc.row + 1; ++i)
	{
		for (int j = loc.col - 1; j <= loc.col + 1; ++j)
		{
			if (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() )
			{
				if (!grid[i][j].hasShip())
					emptyCells.push_back(&grid[i][j]);
			}
		}
	}
	return emptyCells;
}


//////////////////////////////////////////////////////////////////////////
// main will not run
// Ship and Cell classes have unimplemented methods
//////////////////////////////////////////////////////////////////////////

int main()
{


	// Vector example (bad)
	// http://stackoverflow.com/questions/6491251/multi-dimensional-vector-initialization
	// explanation
	//std::vector< std::vector< Cell> > grid(12, std::vector<Cell>(12)); //Same size

	//init ships and place them on the map
	std::vector<Ship*> ships(SHIPS);

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

	// Insert ports on random locations
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

	// Insert treasures on random locations
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


	//insert random values on the Map for the Weather and coords on every cell
	//Print out the Map (grid) in the console and in a txt file
	std::ofstream myfile;
	myfile.open("test.txt", std::ios::out);
	for (int i = 0; i != grid.size(); ++i)
	{
		for (int j = 0; j != grid.size(); ++j)
		{
			grid[i][j].setCoords(Coords(i, j));
			grid[i][j].setWeather((rand() % 10) + 1);
			std::cout << grid[i][j] << std::endl;
			myfile << grid[i][j] << std::endl;
		}
	}
	myfile.close();

	myfile.open("Move1.txt", std::ios::out);
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

	Map test;
	test.moveShips();















	system("pause");
	return 0;
}

/*
int main()
{
	std::vector<int> a(12*12);
	for (int n = 0; n != 12; ++n)
	{
		int t=1;
		t = n*t;
		for (std::vector<int>::iterator it = a.begin()+t; it != a.begin() + 12+t; ++it)
		{
			std::cout << ' ' << *it;
		}
		std::cout << '\n';
	}
	
	

	return 0;
}
*/