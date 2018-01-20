//TODO: add header guards here
#ifndef SICT_passenger_H
#define SICT_passenger_H
#include <cstdio>
#include <cstring>
// TODO: holiday namespace here
#pragma once
using namespace std;
namespace holiday {
	class Passenger {
	private:
		char m_name[32];
		char m_destination[32];
		int  m_departureYear;
		int  m_departureMonth;
		int  m_departureDay;
	public:
		Passenger();
		Passenger(const char* p_name,const char* p_destination);
		void display(bool onlyNames = false) const;
		bool isEmpty() const;
		bool canTravelWith(const Passenger& person) const;
	};
};





// TODO: declare the class Passenger here
// TODO: add the class the attributes,
//       the member function already provided,
//       and the member functions that you must implement


#endif