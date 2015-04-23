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

//half-implemented << operator
std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    os << "Cell \n"
          "Location   :  [" << cell.coords.row << ", " << cell.coords.col << "]" << std::endl;
    os << "Weather    :  " << cell.weather << std::endl;
	//TODO: Print out Rest of info

    return os;
}

//////////////////////////////////////////////////////////////////////////
//TODO: Implement Rest