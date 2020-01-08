#include "Passenger.h"

Passenger::Passenger(LocationTags desti):destination(desti) //&destination verschieben ist doof
{
	std::cout << "Passenger with goal "<< locationNameByTag(this->destination) << " created!\n";
}


Passenger::~Passenger()
{
}

std::string Passenger::getDestination() { return (locationNameByTag(this->destination)); }
