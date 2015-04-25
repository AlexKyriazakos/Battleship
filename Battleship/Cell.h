#ifndef GUARD_Cell_h
#define GUARD_Cell_h

#include "Ship.h"

class Cell 
{
	//Private stuff
	int		weather;
	bool	port;
	bool	treasure;
	Ship*	ship;
	Coords  coords;

public:

	/* \brief Default constructor with initialization list (??????) */
	Cell() : weather(4), port(false), treasure(true), ship(NULL), coords() {}

	//////////////////////////////////////////////////////////////////////////
	// Setters/Getters
	void	setWeather(int weather_);

	void	setPort(bool port_);

	void	setTreasure(int treasure_);

	void	setCoords(Coords coords_);

	void	setShip(Ship* ship_);

	// Comment: Getters are const, since they do not modify the object
	int		getWeather() const;

	bool	hasPort() const;

	Ship*	getShip() const;

	Coords	getCoords() const;

	bool	hasShip() const;
	//////////////////////////////////////////////////////////////////////////

	//We make the std::ostream friend in order to let it read and printout
	//the Cells attributes using the "<<" operator, Ship needs the same
	//Usage:
	// Cell a;
	// std::cout << a;
	// cout is just the system's ostream (output stream)
	friend std::ostream& operator<<(std::ostream& os, const Cell& dt);
};



#endif