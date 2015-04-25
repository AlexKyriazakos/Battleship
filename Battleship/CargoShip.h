#include "Cell.h"


class CargoShip : public Ship
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
			return (std::string("Cargo"));
		return(std::string("C"));
	}

	virtual int getType()
	{
		return CARGO;
	}

};
