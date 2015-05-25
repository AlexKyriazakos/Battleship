#ifndef GUARD_Ship_h
#define GUARD_Ship_h

#include <string>
#include <vector>

class Map;
//simple coordinate structure
struct Coords {
	int row;
	int col;

	Coords() {}
	Coords(int x, int y) { row = x; col = y; }

	//friend Coords operator-(const Coords &c1, const Coords &c2);
	//friend Coords operator+(const Coords &c1, const Coords &c2);
	//friend Coords operator+=(const Coords &c1, const Coords &c2);
};

Coords operator+(const Coords &c1, const Coords &c2);

Coords operator-(const Coords &c1, const Coords &c2);

Coords operator+=(Coords &c1, const Coords &c2);


enum ShipType{
	PIRATE = 0,
	CARGO,
	REPAIR,
	EXPLORER,
	NUMSHIPS
};

class Ship {

public:

	Ship();
	/** \brief Default Constructor */
	Ship(Map* map_); //Will need to initialize members

	// Important
	/** \brief Destructor */
	virtual ~Ship() {} //must declare destructor virtual in case of inheritance

	/** \brief Ship moving method */
	virtual void move(); //not const, changes position
						 //also void, ship takes care of moving (random)

	/** \brief Ship action method, pure virtual */
	virtual void action() = 0;

	virtual std::string getName(bool extended) const = 0;

	virtual int getType() const  = 0; 

	//////////////////////////////////////////////////////////////////////////
	// Setters/Getters
	// Note: Getters are const 
	int getSpeed() const;

	void setSpeed(int speed_);

	void incTreasure(double treasure_);

	void decTreasure(double treasure_);

	double getTreasure() const;

	void incHP(double hp_);

	void decHP(double hp_);

	double getHP() const;

	void setLocation(Coords location_);

	void setLocation(int x_, int y_);

	Coords getLocation() const;
	//////////////////////////////////////////////////////////////////////////
	static int  shipsCreated;

	friend std::ostream& operator<<(std::ostream& os, const Ship& dt);

	Coords		location;
	int			number;
protected: //We want derivatives to have access to them, but users not

	double		currentHp;
	double		maxHp;
	double		treasure;
	
	int			speed;
	Map*		map;
	

};



#endif