#include <iostream>
#include <fstream>
#include "Cell.h"

#define echo(x) std::cout<<#x<<" = "<<x<<std::endl


//////////////////////////////////////////////////////////////////////////
// main will not run
// Ship and Cell classes have unimplemented methods
//////////////////////////////////////////////////////////////////////////

int main()
{
	//Not working anymore
	/*
	Cell test[12][12];
	for (int n = 0; n<12; n++)
		for (int m = 0; m<12; m++)
		{
		test[n][m].port = true;
		test[n][m].ship = false;
		test[n][m].treasure = true;
		test[n][m].weather = 2;
		};
		*/
	
	// Vector example (bad)
	// http://stackoverflow.com/questions/6491251/multi-dimensional-vector-initialization
	// explanation
	//std::vector< std::vector< Cell> > grid(12, std::vector<Cell>(12)); //Same size

	std::vector< std::vector< Cell> > grid(12, std::vector<Cell>(12));


	std::vector<Ship*> ships(20);

	//init ships and place them on the map
	
	for (int i = 0; i != ships.size(); i++)
	{
		int x, y, t;
		x = rand() % 12;
		y = rand() % 12;
		t = rand() % 4;
		if (t == 0)
		{
			ships[i] = new PirateShip;
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
		grid[x][y].setShip(ships[i]);
		ships[i]->setLocation(x, y);
	}

	std::ofstream myfile;
	myfile.open("test.txt", std::ios::out);
	for (int i = 0; i != 12; ++i)
	{
		for (int j = 0; j != 12; ++j)
		{
			grid[i][j].setCoords(Coords(i, j));
			std::cout << grid[i][j] << std::endl;
			myfile << grid[i][j] << std::endl;
		}
	}
	myfile.close();

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