#define _CRT_SECURE_NO_WARNINGS 

#include "Error.h"
#include <iostream>
#include <cstring>

namespace ict{

	Error::Error(){
		m_message = nullptr;
	}
	Error::Error(const char* errorMessage){
		m_message = nullptr;
		message(errorMessage);
	}
	//Error::Error(const Error& em){}

	// destructor
	// ~Error();
	Error::~Error(){
		delete[] m_message;
	}
	// deleted constructor and operator=
//	Error& Error::operator=(const Error& em){}
	// operator= for c-style strings
	Error::operator const char*() const{
		return m_message;
	}
	void Error::operator=(const char* errorMessage){
		clear();
		message(errorMessage);
	}
	// methods

	void Error::clear(){
		delete[] m_message;
		m_message = nullptr;
	}
	bool Error::isClear()const{
		return(m_message == nullptr) ? true : false;
	}
	void Error::message(const char* value){
		delete[] m_message;
		m_message = new char[strlen(value) + 1];
		strcpy(m_message, value);
	}
	Error::operator bool()const{
		return (m_message == nullptr) ? true : false;
	}
	std::ostream& operator<<(std::ostream& ostr, const Error& obj){
		//if (obj.isClear()) ostr << "";
		if (obj.isClear() == false) ostr << obj.operator const char *();
		return ostr;
	}
}