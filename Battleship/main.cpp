#include <iostream>
#include "Cell.h"

//Create Dummy class derivative of ship
class DummyShip : public Ship
{

public:

	//Why virtual again????
	virtual void action()
	{
		//do nothing
	}
};

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
	std::vector< std::vector< Cell> > grid(12, std::vector<Cell>(12)); //Same size

	//Polymorphism
	Ship* testShip = new DummyShip; //Why declare it Ship Pointer?
	//DummyShip* testShip = new DummyShip;   //correct??

	testShip->setSpeed(5); //set some speed

	grid[1][5].setShip(testShip); //assign it to a cell

	//Will print 5
	std::cout << "Cells [1,5] Ship has speed: " << grid[1][5].getShip()->getSpeed() << std::endl;

	std::cout << grid[1][5]; //result of friend ostream operator <<

	return 0;
}