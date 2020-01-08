#include "Sing_MasterGenerator.h"

//Konstruktor fuer Singleton: Master Generator
Sing_MasterGen::Sing_MasterGen() 
{
}


void Sing_MasterGen::genAirport(unsigned numbOfAirpToGen)
{
	Sing_MasterGen* airportGen = &Sing_MasterGen::getInstance();
	
	for (unsigned i(0); i < numbOfAirpToGen; i++)
	{
	
		if (airportGen->AirportList.size() < locationCount())
			airportGen->AirportList.push_back(*new Airport((LocationTags) airportGen->AirportList.size())); //füge Airp zu AirpList 
		else
			std::cout << "Out of Location Names!\n";

	}
	for (auto& i : airportGen->AirportList)//update alle Airports TravellerArray Size
		i.TravelerMatrix.resize(locationCount());
}
void Sing_MasterGen::genPassenger(unsigned numOfNewPass, unsigned start, unsigned desti)
{
	Sing_MasterGen* airportGen = &Sing_MasterGen::getInstance();
	airportGen->genPassenger(numOfNewPass, (LocationTags) start, (LocationTags) desti);
}
void Sing_MasterGen::genPassenger(unsigned numOfNewPass, LocationTags start, LocationTags desti)
{
	//Sing_AirportGen& airportGen = Sing_AirportGen::getInstance(); //alternative auch ok
	auto& airportGen = Sing_MasterGen::getInstance();
	
	if ((int)desti < airportGen.AirportList.size() && (int)start < airportGen.AirportList.size() && desti != start)//nur vorhandene Orte koennen ziel sein
	{
		for (unsigned i = 0; i < numOfNewPass; i++)
		{
			std::cout << locationNameByTag(start) << ": ";
			Passenger p = *new Passenger(desti);
			airportGen.AirportList[(unsigned)start].TravelerMatrix.at((uint32_t)desti).push_back(p);
		}
	}
	else
	{
		std::cout << "invalid start/destination!\n";
	}
}

void Sing_MasterGen::genCarrier(unsigned numOfNewCarr,  unsigned start, unsigned capacity )
{ 
	Sing_MasterGen* airportGen = &Sing_MasterGen::getInstance();
	airportGen->genCarrier( numOfNewCarr, (LocationTags)start, capacity);
}
void Sing_MasterGen::genCarrier(unsigned numOfNewCarr, LocationTags start, unsigned capacity)
{
	Sing_MasterGen* airportGen = &Sing_MasterGen::getInstance();
	for (unsigned i(0); i < numOfNewCarr; i++)
	{
		std::cout << locationNameByTag(start) << ": ";
		airportGen->AirportList[(int32_t)start].CarrierList.push_back(*new Carrier(capacity, start));//start==destination
	}
}


void Sing_MasterGen::printGlobalTravelerList() 
{ 
	Sing_MasterGen* airportGen = &Sing_MasterGen::getInstance();
	for (auto& i : airportGen->AirportList)
		i.printTravelerList();
}
