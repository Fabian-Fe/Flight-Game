#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>

#include "Carrier.h"
#include "Airport.h"
#include "Passenger.h"
#include "Sing_MasterGenerator.h" 
#include "LocationMapping.h"


int main()
{
	using SMG = Sing_MasterGen; //inzwischen Generiert es Locations, Carrier, Passenger

	SMG::genAirport(3);
	SMG::genPassenger(5, 0, 1);//# Ort Ziel
	SMG::genPassenger(5, 0, 2);//# Ort Ziel
	SMG::genPassenger(5, 1, 2);//# Ort Ziel
	SMG::genCarrier(2, 0, 5);//# Ort capacity
	SMG::getInstance().AirportList.at(0).printTravelerList();
	SMG::getInstance().AirportList.at(0).printCarrierList();

	std::cout << "\n\n\n\n";
	SMG::getInstance().AirportList.at(0).allEmbarkAllAndGo();
	
	//SMG::getInstance().printGlobalTravelerList();

}
