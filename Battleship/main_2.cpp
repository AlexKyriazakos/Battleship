#include <iostream>
#include <fstream>

#include "Map.h"

#define echo(x) std::cout<<#x<<" = "<<x<<std::endl

int main()
{
	Map Battleground;
	//Battleground.initCoords();
	Battleground.placeShips();
	Battleground.placePorts();
	Battleground.placeTreasure();
	int i = 0;
	while (!Battleground.deadShips())
	{
		Battleground.checkWeather();
		Battleground.checkTreasure();
		Battleground.checkPort();
		Battleground.moveShips();
		Battleground.actionShips();
		i++;
	}
	std::cout << "It took " << i << " loops." << std::endl;
	std::ofstream myfile;
	myfile.open("Grid6.txt", std::ios::out);
	for (int i = 0; i != GRIDSIZE; ++i)
	{
		for (int j = 0; j != GRIDSIZE; ++j)
		{
			myfile << Battleground.grid[i][j] << std::endl;
		}
	}
	myfile.close();
	system("pause");
	return 0;
}