#pragma once
#include  <iostream>
#include <vector>
#include <string>
//#include <iterator>
#include "Passenger.h"
#include "Carrier.h"
#include "LocationMapping.h"

class Carrier;

class Airport
{
	friend class Carrier; //friend bei der Dekl v Daten nicht zulaessig
public:
	Airport(LocationTags);
	~Airport();
	LocationTags location;
	std::vector< std::vector<Passenger> > TravelerMatrix;
	//std::vector<Passenger> TravelerList;
	std::vector<Carrier> CarrierList;


	void printTravelerList();
	void printCarrierList();
	std::string getName();
	void setDestinationTo(unsigned, LocationTags);
	void allEmbarkAllAndGo();
};

