#include "Carrier.h"

Carrier::Carrier(unsigned capa, LocationTags Destination):destination(Destination)
{

	this->PassengerList.reserve (capa);

#ifdef _DEBUG
	std::cout << "Carrier created! with its Lists capacity " << getCapacity() <<"\n";
#endif
}

Carrier::~Carrier()
{
#ifdef _DEBUG
	std::cout << "Carrier " << this << " destroyed!\n";
#endif
}

std::string Carrier::getDestination() { return (locationNameByTag(this->destination)); }

int Carrier::getCapacity() 
{
	return PassengerList.capacity();
}
int Carrier::getSize()
{
	return PassengerList.size();
}

/*
void Carrier::embark(Passenger passenger)
{
	if (PassengerList.size() < PassengerList.capacity()-PassengerList.size())
	{
		PassengerList.push_back(passenger);

		#ifdef _DEBUG
		std::cout << "\nEmbarkment of " << &passenger << " from " << locationTag locationNameByTag(this->destination)
			<< " makes new passenger List size: " << PassengerList.size() << std::endl;
	}
	else
	{
		std::cout << "\nEmbarkment failed, " << &passenger << " could not be embarked. passenger List size is "
			<< PassengerList.size() << " and ";
		#endif
	}

	std::cout << "capaciy of Passengerlist is " << PassengerList.capacity() << "\n";

}
*/