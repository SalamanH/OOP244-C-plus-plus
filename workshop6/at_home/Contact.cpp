#include "Contact.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
namespace communication {

	Contact::Contact(){
		strcpy(m_name, "");
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;
	}
	Contact::Contact(char name[], long long* phoneNumbers, int numOfPhoneNumbers){
		
		if (name == nullptr) name = "";
		if (phoneNumbers == nullptr) phoneNumbers = 0;
		string temp2 = name;
		
			strcpy(m_name, name);
	
			
		m_noOfPhoneNumbers = numOfPhoneNumbers;
	
		if (phoneNumbers == nullptr)
			m_phoneNumbers = phoneNumbers;
		else{
			m_phoneNumbers = new long long[numOfPhoneNumbers];
			int j = 0;
			for (int i = 0; i != numOfPhoneNumbers; i++){
				if (phoneNumbers[i] > 11111111111 && phoneNumbers[i] < 1000000000000)
				{
					m_phoneNumbers[j] = phoneNumbers[i];
					j++;

				}

			}
			m_noOfPhoneNumbers = j;
		}

	}
	Contact::Contact(const Contact& instance){}
	void Contact::operator=(Contact var){
		/*strcpy(m_name,var.m_name);
		m_noOfPhoneNumbers = var.m_noOfPhoneNumbers;
		for (int i = 0; i != var.m_noOfPhoneNumbers; i++){
			m_phoneNumbers[i] = var.m_phoneNumbers[i];
		}*/
	}

	void Contact::addPhoneNumber(long long addNumber) {

		string name_holder = m_name;
		long long* phoneNumber_holder = nullptr;
		int numOFPhones = m_noOfPhoneNumbers + 1;
		phoneNumber_holder = new long long[numOFPhones];
		
		for (int i = 0; i != m_noOfPhoneNumbers; i++){
			phoneNumber_holder[i] = m_phoneNumbers[i];
		}
		m_noOfPhoneNumbers++;
		this->m_phoneNumbers = new long long[m_noOfPhoneNumbers];
		for (int i = 0; i != m_noOfPhoneNumbers; i++){
			if (i == m_noOfPhoneNumbers - 1) m_phoneNumbers[i] = addNumber;
			else m_phoneNumbers[i] = phoneNumber_holder[i];
		}
		
	}
	Contact::~Contact(){
	//	delete [] m_name;
	//	delete[] m_phoneNumbers;

	}
	void Contact::display() const{
		if (isEmpty()){
			cout << "Empty contact!" << endl;
		}
		else {
			cout << m_name << endl;
			for (int i = 0; i != m_noOfPhoneNumbers; i++)
			{
				if (to_string(m_phoneNumbers[i]).length() == 12)
				{
					cout << "(+" << to_string(m_phoneNumbers[i]).substr(0, 2) << ") " << to_string(m_phoneNumbers[i]).substr(2, 3)
						<< " " << to_string(m_phoneNumbers[i]).substr(5, 3) << "-" << to_string(m_phoneNumbers[i]).substr(8, 4) << endl;
				}
				else
					cout << "(+" << to_string(m_phoneNumbers[i]).substr(0, 1) << ") " << to_string(m_phoneNumbers[i]).substr(1, 3)
					<< " " << to_string(m_phoneNumbers[i]).substr(4, 3) << "-" << to_string(m_phoneNumbers[i]).substr(7, 4) << endl;
			}
		}
	}

	bool Contact::isEmpty() const{
		string temp2 = m_name;
		return (temp2.length() == 0) ? true : false;
	}
}
