
#include <iostream>
#include "passenger.h" 
#include <cstring>

using namespace std;
using namespace holiday;

	Passenger::Passenger(const char* p_name,
						const char* p_destination,
						int p_departureYear,
						int p_departureMonth,
						int p_departureDay){

		if (p_name == nullptr || 
			p_destination == nullptr ||
			strlen(p_name) == 0 ||
			strlen(p_destination) == 0 ||
			p_departureYear > 2020 || 
			p_departureYear < 2017 ||
			p_departureMonth <1 ||
			p_departureMonth > 13 ||
			p_departureDay <1 ||
			p_departureDay > 31){
			*this = Passenger();
		}
		else{
				strcpy(m_name, p_name);
				strcpy(m_destination, p_destination);
				m_departureDay = p_departureDay;
				m_departureMonth =p_departureMonth;
				m_departureYear =p_departureYear;
		}
		
	};
	Passenger::Passenger(){
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_departureYear = 0;
		m_departureMonth = 0;
		m_departureDay = 0;
	};
	void Passenger::display(const Passenger* arrPassengers, int size, int matches,  bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			
			if (false == nameOnly)
			{
				cout << this->m_name << " will travel to " << this->m_destination << ". "
					<< "The journey will start on "
					<< this->m_departureYear << "-"
					<< this->m_departureMonth << "-"
					<< this->m_departureDay
					<< "." << endl;
			}
		
		   if (nameOnly == true) {
			   int b = 0;
			   if (size == matches){
				   cout << "Everybody can join Ross on vacation!" << endl;
					   
			   }
			   
			   cout << this->m_name << " will be accompanied by ";
			   for (int i = 0; i < size; i++){
				   if (this->canTravelWith(arrPassengers[i])){
					   b++;
					   cout << arrPassengers[i].m_name;
					   if (b == matches)
						   cout << ".";
					   else
						   cout << ", ";
				   }
			   }
			   cout << endl;
		
		   }
		

		}
		else
		{
			cout << this->m_name << "Invalid passenger!" << endl;
		}

		
	}
	bool Passenger::isEmpty()const{
		
		return (m_name[0] == '\0');
	};
	bool Passenger::canTravelWith(const Passenger& person) const {
		return (strcmp(this->m_destination, person.m_destination) == 0 && 
			(m_departureDay == person.m_departureDay) &&
			(m_departureMonth == person.m_departureMonth) &&
			(m_departureYear == person.m_departureYear));

	}
	void Passenger::travelWith(const Passenger* arrPassengers, int size){
		int a= 0;
		if (arrPassengers == nullptr || size <= 0)
			cout << "Nobody can join " << this->m_name << " on vacation!" << endl;
		else {
			for (int i = 0; i < size; i++){
				if (this->canTravelWith(arrPassengers[i])){
					a++;

				}

			}

			this->display(arrPassengers,size, a,  true);



		}

	}