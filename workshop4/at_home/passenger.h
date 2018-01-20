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
		Passenger(const char* p_name,
				  const char* p_destination,
				  int p_departureYear, 
			   	  int p_departureMonth, 
				  int p_departureDay
				  );
		void display(const Passenger* arrPassengers='\0', int size = 0, int matches = 0, bool nameOnly = false) const;
		bool isEmpty() const;
		bool canTravelWith(const Passenger& person) const;
		void travelWith(const Passenger* arrPassengers, int size);
	};
};





// TODO: declare the class Passenger here
// TODO: add the class the attributes,
//       the member function already provided,
//       and the member functions that you must implement


#endif