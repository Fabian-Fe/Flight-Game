#pragma once
#include <iostream>
#include <vector>
#include "Passenger.h"

class Carrier
{
public:
	Carrier(unsigned, LocationTags); //Args capacity in form von Groesse der PassengerList und Ziel
	~Carrier();
	
	LocationTags destination;
	std::vector<Passenger> PassengerList; //ueberlegen ob array, weil feste groesse per CONSTR
	std::string getDestination();
	int getCapacity();
	int getSize();

	
};

