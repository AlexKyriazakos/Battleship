
#ifndef GUARD_Map_h
#define GUARD_Map_h

#include <string>
#include <vector>

#include "Ship.h"
#include "Cell.h"
#include "Definitions.h"
#include "CargoShip.h"
#include "RepairShip.h"
#include "PirateShip.h"
#include "ExplorerShip.h"

class Map {

public:

	/** \brief Constructor with default parameters */
	Map(int size = GRIDSIZE, int shipNum = SHIPS) : grid(size, std::vector<Cell>(size)), ships(shipNum) 
	{
		initCoords(); 
	}
	//NOTE: implement action() on ships. Since the ships will need to ask the Map for info, you need			}   I DO
	//to pass the Map pointer to each ship, so you should modify the Ship ctor to take a Map* as argument		}    NOT
	//and use the 2nd vector ctor (num, elem) above e.g. ships(shipNum, Ship(this)) since Ship::Ship(Map* map)	} UNDERSTAND

	/** \brief default destructor */
	~Map();

	std::vector< std::vector<Cell> > grid;

	std::vector<Ship*> ships;

	//Should make similar methods (for ships to use) that return:
	// 1)neighboring ships (speed argument?) ---- Can't we just getShip() from the *Cell vector?
	// 2)Cells occupied by neighboring ships ---- DONE
	// 3)simple Cell* getCell(int col, int row) since Ships will be placing themselves on new Cells ---- DONE (I think)
	std::vector<Cell*> findEmptyCells(Ship& ship);
	std::vector<Cell*> findFullCells(Ship& ship);
	std::vector<Cell*> findNeighbourCells(Ship& ship);
	Cell* getCell(int row, int col);

	// This should be called in the ctor  ---- DONE
	void initCoords();

	void placeShips();
	
	//Change to get percentage of ports as argument ---- DONE
	// placePorts(0.3). Needs proper check that arg < 1
	void placePorts(double portPercent = PORT);

	//Same as above ---- DONE
	void placeTreasure(double treasurePercent = TREASURE);
	
	//if the above is implemented, the Ships should now move themselves and ask the Map for possible
	//destinations, so this will be reduced to : for all ships -> ship.move();
	void moveShips();
	void actionShips();

	//Get the Weather damage
	void checkWeather();

	//Get the Treasure
	void checkTreasure();

	//Check if any ships are in/near ports
	void checkPort();

	int deadShips();

	void printInfo();

	//Try to implement a full update cycle:
	// 1. move, 2.action, 3.remove dead ships, 4. check for winner (treasure target), 0.apply weather damage and treasure increase
	// 1,2 are ship responsibility
	// 3,4,0 are Map responsibility
};



#endif