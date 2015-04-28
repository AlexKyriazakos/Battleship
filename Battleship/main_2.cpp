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
	Battleground.moveShips();


	system("pause");
	return 0;
}