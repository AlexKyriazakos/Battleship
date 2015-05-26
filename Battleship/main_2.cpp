#include <iostream>
#include <fstream>

#include "Map.h"
#include "Utils.h"

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
		//////////////////////////////////////////////////////////////////////////
		// Minimal example of getAsyncKey usage
		if (getAsyncKey() == 'p') //if player presses "p"
		{
			clearScreen();
			std::cout << "You just paused" << std::endl;

			Battleground.printInfo();

			//offer an option
			std::cout << "Press Space(' ') to continue" << std::endl;

			//wait forever until he presses space
			while (1)
			{
				int k = tolower(_getch());
				if (k == ' ') //if key is space continue
					break;
			}
		}

		//Also add a little pause and print current round
		Sleep(200); //sleep 200ms
		clearScreen();
		std::cout << "Round: " << i << std::endl;
		//Boom!
		//////////////////////////////////////////////////////////////////////////
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