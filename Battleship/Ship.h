#ifndef GUARD_Ship_h
#define GUARD_Ship_h

#include <string>
#include <vector>

//simple coordinate structure
struct Coords {
	int row;
	int col;

	Coords() { row = 0; col=0; }
};

enum ShipType{
	DUMMY = 0,
	DUMMIER,
	PEIRATIKO,
	EMPORIKO,
	NUMSHIPS
};

class Ship {

public:

	/** \brief Default Constructor */
	Ship(); //Will need to initialize members

	// Important
	/** \brief Destructor */
	virtual ~Ship() {} //must declare destructor virtual in case of inheritance

	/** \brief Ship moving method */
	virtual void move(); //not const, changes position
						 //also void, ship takes care of moving (random)

	/** \brief Ship action method, pure virtual */
	virtual void action() = 0;

	virtual std::string getName(bool extended) = 0;

	virtual int getType() = 0;

	//////////////////////////////////////////////////////////////////////////
	// Setters/Getters
	// Note: Getters are const 
	int getSpeed() const;

	void setSpeed(int speed_);

	void incTreasure(double treasure_);

	void decTreasure(double treasure_);

	int getTreasure() const;

	void incHP(double hp_);

	void decHP(double hp_);

	double getHP() const;
	//////////////////////////////////////////////////////////////////////////
	static int  shipsCreated;
protected: //We want derivatives to have access to them, but users not

	double		currentHp;
	double		maxHp;
	double		treasure;
	
	int			speed;
	Coords		location;

};



#endif