#include "Cell.h"


class ExplorerShip : public Ship
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
			return (std::string("Explorer"));
		return(std::string("E"));
	}

	virtual int getType()
	{
		return EXPLORER;
	}

};
