#include "Cell.h"


class PirateShip : public Ship
{

public:

	//Why virtual again????
	virtual void action()
	{
		//do nothing
	}

	virtual std::string getName(bool extended) const
	{
		if (extended)
			return (std::string("Pirate"));
		return(std::string("P"));
	}

	virtual int getType()
	{
		return PIRATE;
	}

protected:

	double damage;
};

