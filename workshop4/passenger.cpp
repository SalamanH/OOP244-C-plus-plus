
#include <iostream>
#include "passenger.h" 
#include <cstring>

using namespace std;
using namespace holiday;

	Passenger::Passenger(const char* p_name,const char* p_destination){
		

		if (p_name == nullptr || p_destination == nullptr){
			*this = Passenger();
		}
		if (p_name != nullptr && p_destination != nullptr){
			strcpy(m_name, p_name);
			strcpy(m_destination, p_destination);
			m_departureDay = 01;
			m_departureMonth = 07;
			m_departureYear = 2017; 

		}

	};
	Passenger::Passenger(){
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_departureYear = 0;
		m_departureMonth = 0;
		m_departureDay = 0;
	};
	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
					<< "The journey will start on "
					<< this->m_departureYear << "-"
					<< this->m_departureMonth << "-"
					<< this->m_departureDay
					<< "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}
	}
	bool Passenger::isEmpty()const{
		bool result = true; 
		if (strlen(m_name) > 0 && strlen(m_destination) > 0){
			result = false;
			
		}
		return result; 
	};
	bool Passenger::canTravelWith(const Passenger& person) const {
		return (strcmp(this->m_destination, person.m_destination) == 0 && (m_departureDay == person.m_departureDay));

	}

