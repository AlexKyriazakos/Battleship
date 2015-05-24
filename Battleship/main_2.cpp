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
	Battleground.checkWeather();
	Battleground.checkTreasure();

	std::ofstream myfile;
	myfile.open("Grid.txt", std::ios::out);
	for (int i = 0; i != GRIDSIZE; ++i)
	{
		for (int j = 0; j != GRIDSIZE; ++j)
		{
			myfile << Battleground.grid[i][j] << std::endl;
		}
	}
	myfile.close();
	Battleground.moveShips();


	system("pause");
	return 0;
}