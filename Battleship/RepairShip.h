#include "Cell.h"


class RepairShip : public Ship
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
			return (std::string("Repair"));
		return(std::string("R"));
	}

	virtual int getType()
	{
		return REPAIR;
	}

};
