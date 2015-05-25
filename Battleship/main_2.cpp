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

	std::cout << "          SHIPS" << std::endl;
	for (int i = 0; i != GRIDSIZE+2; ++i)
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
				if (Battleground.grid[i - 2][j].getShip())
					std::cout << Battleground.grid[i - 2][j].getShip()->getName(false) << "|";
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
				std::cout << Battleground.grid[i - 2][j].getWeather()-1 << "|";
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
				if (Battleground.grid[i - 2][j].hasPort())
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
				if (Battleground.grid[i - 2][j].hasTreasure())
					std::cout << "T|";
				else
					std::cout << " |";
			}
			std::cout << std::endl;
		}

	}


	int i = 0;
	/*
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
	*/
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