#include <iostream>
#include "Cell.h"

#define echo(x) std::cout<<#x<<" = "<<x<<std::endl

//Create Dummy class derivative of ship
class DummyShip : public Ship
{

public:

	//Why virtual again????
	virtual void action()
	{
		//do nothing
	}

	virtual std::string getName(bool extended)
	{
		if (extended)
			return (std::string("Dummy"));
		return(std::string("D"));
	}

	virtual int getType()
	{
		return DUMMY;
	}
};

class DummierShip : public Ship
{

public:

	//Why virtual again????
	virtual void action()
	{
		//do nothing
	}

	virtual std::string getName(bool extended)
	{
		return extended ? std::string("Dummier") : std::string("D");
	}

	virtual int getType()
	{
		return DUMMIER;
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
	//std::vector< std::vector< Cell> > grid(12, std::vector<Cell>(12)); //Same size

	std::vector< std::vector< Cell> > grid(12, std::vector<Cell>(12));

	echo(grid[0][0]);

	std::vector<Ship*> ships(2);

	//init ships
	ships[0] = new DummierShip;
	ships[1] = new DummyShip;

	for (int i = 0; i != ships.size(); i++)
	{
		if (ships[i]->getType() == DUMMY)
			std::cout << "we have a dummy" << std::endl;
		break;
	}

	//Polymorphism
	Ship* testShip = new DummyShip; //Why declare it Ship Pointer?
	//DummyShip* testShip = new DummyShip;   //correct??

	testShip->setSpeed(5); //set some speed

	grid[1][5].setShip(testShip); //assign it to a cell

	//Will print 5
	std::cout << "Cells [1,5] Ship has speed: " << grid[1][5].getShip()->getSpeed() << std::endl;

	std::cout << grid[1][5]; //result of friend ostream operator <<

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