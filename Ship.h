#ifndef GUARD_Ship_h
#define GUARD_Ship_h

#include <string>
#include <vector>

class Ship {
public:


	std::string move() const;
	virtual void action() = 0;


	double currenthp, maxhp, treasure;
	int speed;
};



#endif