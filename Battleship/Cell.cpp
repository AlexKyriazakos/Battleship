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

//half-implemented << operator
std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    os << "Cell \n"
          "Location\t:  [" << cell.coords.row << ", " << cell.coords.col << "]" << std::endl;
    os << "Weather\t\t:  " << cell.weather << std::endl;
	os << "Treasure\t:  " << cell.treasure << std::endl;
	os << "Port\t\t:  " << cell.port << std::endl;
	os << "Ship\t\t:  " << cell.getShip() << " with speed: " << cell.getShip()->getSpeed() << std::endl;
	//TODO: Print out Rest of info

    return os;
}

//////////////////////////////////////////////////////////////////////////
//TODO: Implement Rest