#include "Cell.h"

void Cell::setWeather(int weather_)
{
	//If in limits, set
	if (weather_ > 0 && weather_ <= 10)
		weather = weather_;
}

int Cell::getWeather() const
{
	return weather;
}

void Cell::setPort(bool port_)
{
	port = port_;
}

bool Cell::hasPort() const
{
	return port;
}

Ship* Cell::getShip() const
{
	return ship;
}

void Cell::setShip(Ship* ship_)
{
	ship = ship_;
}

void Cell::setCoords(Coords coords_)
{
	coords = coords_;
}

bool Cell::hasShip() const
{
	return ship ? true : false;
}

void Cell::setTreasure(bool treasure_)
{
	treasure = treasure_;
}

bool Cell::hasTreasure() const
{
	return treasure;
}

Coords Cell::getCoords() const
{
	return coords;
}

void Cell::removeShip()
{
	ship = NULL;
}

//half-implemented << operator
std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    os << "Cell \n"
          "Location :  [" << cell.coords.row << "," << cell.coords.col << "]" << std::endl;
    os << "Weather  :  " << cell.weather << std::endl;
	os << "Treasure :  " << cell.treasure << std::endl;
	os << "Port     :  " << cell.port << std::endl;
	if (cell.hasShip())
		os << "The Cell has a " <<*cell.ship << std::endl;
		//os << "We have a " << cell.getShip()->getName(true) << " ship" << std::endl;
	else
		os << "The Cell is empty" << std::endl;
	//TODO: Print out Rest of info

    return os;
}

//////////////////////////////////////////////////////////////////////////
//TODO: Implement Rest