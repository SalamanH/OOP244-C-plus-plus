// TODO: add header guard
#ifndef communication_contact_h
#define communication_contact_h
#include <iostream>
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Waddress"

// TODO: add namespace here
using namespace std;
namespace communication {
	class Contact
	{
		char m_name[20];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
	public:
		// TODO: add the default constructor here
		Contact();
		// TODO: add the constructor with parameters here
		Contact(char name[21], long long* phoneNumbers, int numOfPhoneNumbers);
		Contact(const Contact& instance); // do something with this 
		// TODO: add the destructor here
		~Contact();
		// TODO: add the display function here
		void display() const;
		// TODO: add the isEmpty function here
		bool isEmpty() const;
		void addPhoneNumber(long long addNumber);
		void operator=(Contact var);
	public:
		//Contact(const Contact& other) = delete;
		//Contact& operator=(const Contact& other) = delete;
	};
}

#endif