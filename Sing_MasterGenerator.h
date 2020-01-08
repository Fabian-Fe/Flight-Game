#pragma once
#include "Airport.h"
#include <iostream>
#include <vector>
#include "LocationMapping.h"



class Sing_MasterGen	//Singleton: Location Generator
{
public:
	static Sing_MasterGen& getInstance()
	{
		static Sing_MasterGen    instance; 	// Guaranteed to be destroyed.
						// Instantiated on first use.
		return instance;
	}
	
private:
	Sing_MasterGen();
public:
	Sing_MasterGen(Sing_MasterGen const&)	= delete;
	void operator =(Sing_MasterGen const&)	= delete;
	

	std::vector<Airport> AirportList;
	//std::vector<Passenger> GlobalPassengerList; //koennte man fuer abgebaute Obj ohne ort zum neu verteilen nutyen
	static void genAirport(unsigned);//numOfNewAirports

	static void genPassenger(unsigned, unsigned, unsigned);	//fuehrt zu casted
	static void genPassenger(unsigned, LocationTags, LocationTags);	//generiert nPassagiere an bestimmter Location mit Ziel

	static void genCarrier(unsigned, unsigned, unsigned); //fuehrt zu casted
	static void genCarrier(unsigned, LocationTags, unsigned);//numOfNewCarr, capacity, start==desti
	
	void printGlobalTravelerList();

};


