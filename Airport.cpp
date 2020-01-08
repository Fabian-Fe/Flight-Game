#include "Airport.h"

Airport::Airport(LocationTags locationTags):location(locationTags)
{
	std::cout << "Location "<< getName() <<" created!\n";
	TravelerMatrix.reserve(locationCount());
}

Airport::~Airport()
{
}

void Airport::printTravelerList() 
{ 
	int destiCounter=0;
	std::cout<< getName() << ": TravelerList: ";
	for (auto& travelerByDesti : TravelerMatrix)
	{
		if (travelerByDesti.empty() != true)
		{
			std::cout << "\tWith Destination \t" << locationNameByTag((LocationTags)destiCounter) << ": \n\t\t\t\t\t\t";
		 
			for (auto& traveler : travelerByDesti)
			{
				std::cout << &traveler << ", ";
			}
			std::cout << "\n\t\t";
		}
		destiCounter++;

	}
	std::cout<< std::endl;
}
void Airport::printCarrierList()
{
	std::cout << getName() << ": CarrierList: ";
	for (auto &carrier : CarrierList)
	{
		std::cout  << "\t" << &carrier << " with capacity " <<  carrier.PassengerList.capacity() <<", " << std::endl << "\t\t";
	}
	std::cout << std::endl;
}

std::string Airport::getName()
{
	return (locationNameByTag(this->location)); // als wenn inline INNERHALB diesen Scopes in diese Funktion reingepasted wird.
}

void Airport::setDestinationTo(unsigned carrierFromList, LocationTags newDestination)
{	
	CarrierList.at(carrierFromList).destination = newDestination;	
}

void Airport::allEmbarkAllAndGo()
{ 
	std::cout << getName()<<":" ;
	for (int i = 0; i < locationCount(); i++)//check ob 0 indexed
	{
		if (((std::vector<Passenger>)TravelerMatrix.at(i)).size() > 0) // funktioniert size comparison nicht?
		{
			std::cout << "\t" << TravelerMatrix.at(i).size() << " Passenger waiting with Destination " << locationNameByTag((LocationTags)i) << std::endl;
			for (auto& c : CarrierList)
			{
				int freeSeats = c.getCapacity() - c.getSize();
				std::cout << &c << "s capacity:" << c.getCapacity() << " und belegte Seats: " << c.getSize() << ", also freie Sitze: " << freeSeats << std::endl;
				if (freeSeats > 0)
					std::cout << &c << " hast " << freeSeats << " freeSeats\n";
				//hier passiert das Einladen!
			}
		}
	}
	
	
	//andGo
}

