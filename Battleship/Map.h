
#ifndef GUARD_Map_h
#define GUARD_Map_h

#include <string>
#include <vector>

#include "Cell.h"
#include "Ship.h"
#include "Definitions.h"


class Map {

public:
	Map() : grid(GRIDSIZE, std::vector<Cell>(GRIDSIZE)), ships(SHIPS) {}




	std::vector< std::vector<Cell> > grid;
	std::vector<Ship*> ships;

	std::vector<Cell*> findEmptyCells(Ship& ship);
	
	void initCoords();
	void placeShips();
	void placePorts();
	void placeTreasure();
	
	
	
	
	void moveShips();




};



#endif