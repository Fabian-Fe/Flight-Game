#pragma once
#include <iostream>

static const  std::string locNames[]{ "London", "New York", "Paris","Berlin" ,"Moskaw", "Singapore" , "Tokyo",
		"Hong Kong", "Dubai", "Beijing", "Sydney","Los Angeles", "San Francisco", "Cape Town", "Toronto", "Rio", "Istanbul", "Burgdorf" }; //als static const Array in header

static const enum class LocationTags:int32_t //typsicherheit einen unsigned int per bezeichner auszuwaehlen 
{
	London		= 0, //kein String, ein Bezeichner
	NewYork		= 1,
	Paris		= 2,
	Berlin		= 3,
	Moskaw		= 4,
	Singapore	= 5,
	Tokyo		= 6,
	HongKong	= 7,
	Dubai		= 8,
	Beijing		= 9,
	Sydney		=10,
	LosAngeles	=11,
	SanFrancisco=12,
	CapeTown	=13,
	Toronto		=14,
	Rio			=15,
	Istanbul	=16,
	Burgdorf	=17
};//"static ": Ignoriert auf der linken Seite von "const LocationTags", wenn keine Variable deklariert wurde


inline static std::string locationNameByTag(LocationTags tag) { return locNames[(uint32_t)tag]; }
inline static uint32_t locationCount() { return sizeof(locNames) / sizeof(*locNames); }
