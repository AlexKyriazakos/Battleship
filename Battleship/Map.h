
#ifndef GUARD_Map_h
#define GUARD_Map_h

#include <string>
#include <vector>

#include "Cell.h"
#include "Ship.h"
#include "Definitions.h"


class Map {

public:

	/** \brief Constructor with default parameters */
	Map(int size = GRIDSIZE, int shipNum = SHIPS) : grid(size, std::vector<Cell>(size)), ships(shipNum) {}
	//NOTE: implement action() on ships. Since the ships will need to ask the Map for info, you need
	//to pass the Map pointer to each ship, so you should modify the Ship ctor to take a Map* as argument
	//and use the 2nd vector ctor (num, elem) above e.g. ships(shipNum, Ship(this)) since Ship::Ship(Map* map)

	/** \brief default destructor */
	~Map();

	std::vector< std::vector<Cell> > grid;

	std::vector<Ship*> ships;

	//Should make similar methods (for ships to use) that return:
	// 1)neighboring ships (speed argument?)
	// 2)Cells occupied by neighboring ships
	// 3)simple Cell* getCell(int col, int row) since Ships will be placing themselves on new Cells
	std::vector<Cell*> findEmptyCells(Ship& ship);

	// This should be called in the ctor
	void initCoords();

	void placeShips();
	
	//Change to get percentage of ports as argument
	// placePorts(0.3). Needs proper check that arg < 1
	void placePorts();

	//Same as above
	void placeTreasure();
	
	//if the above is implemented, the Ships should now move themselves and ask the Map for possible
	//destinations, so this will be reduced to : for all ships -> ship.move();
	void moveShips();

	//Try to implement a full update cycle:
	// 1. move, 2.action, 3.remove dead ships, 4. check for winner (treasure target), 0.apply weather damage and treasure increase
	// 1,2 are ship responsibility
	// 3,4,0 are Map responsibility
};



#endif