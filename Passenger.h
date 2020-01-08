#pragma once
#include <iostream>
#include <string>
#include "LocationMapping.h"



class Passenger
{
public:
	Passenger(LocationTags);
	~Passenger();
	LocationTags destination;
	std::string getDestination();
};

