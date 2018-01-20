#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
#include "POS.h"
using namespace std;

namespace ict{
	void Date::set(){
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		m_day = lt.tm_mday;
		m_mon = lt.tm_mon + 1;
		m_year = lt.tm_year + 1900;
		if (dateOnly()){
			m_hour = m_min = 0;
		}
		else{
			m_hour = lt.tm_hour;
			m_min = lt.tm_min;
		}
	}

	int Date::value()const{
		return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
	}

	int Date::mdays()const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
		mon--;
		return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
	}

	// constructors 
	Date::Date(){
		m_dateOnly = false;
		this->set();
	}

	Date::Date(int year, int mon, int day){
		m_dateOnly = true;
		m_readErrorCode = NO_ERROR;
		m_year = year;
		m_mon = mon;
		m_day = day;
		m_hour = m_min = 0;
	}

	Date::Date(int year, int mon, int day, int hour, int min){
		m_dateOnly = false;
		m_readErrorCode = NO_ERROR;
		m_year = year;
		m_mon = mon;
		m_day = day;
		m_hour = hour;
		m_min = min;
	}
	bool Date::operator==(const Date& D)const{
		return (this->value() == D.value()) ? true : false;
	}
	bool Date::operator!=(const Date& D)const{
		return (this->value() != D.value()) ? true : false;
	}
	bool Date::operator<(const Date& D)const{
		return (this->value() < D.value()) ? true : false;
	}
	bool Date::operator>(const Date& D)const{
		return (this->value() > D.value()) ? true : false;
	}
	bool Date::operator<=(const Date& D)const{
		return (this->value() <= D.value()) ? true : false;
	}
	bool Date::operator>=(const Date& D)const{
		return (this->value() >= D.value()) ? true : false;
	}
	int Date::errCode()const{
		return m_readErrorCode;
	}
	bool Date::bad()const{
		return (m_readErrorCode != 0) ? true : false;
	}
	bool Date::dateOnly()const{
		return m_dateOnly;
	}
	void Date::dateOnly(bool value){
		m_dateOnly = value;
		if (value == true) m_hour = m_min = 0;
	}
	std::istream& Date::read(std::istream& istr){
		//std::cout << std::endl << "inside " << std::endl;
		int m_year2;
		int m_mon2;
		int m_day2;
		m_readErrorCode = NO_ERROR;
		istr >> m_year2;
		m_year = m_year2;
		if (istr.get() != '/'){
			m_readErrorCode = CIN_FAILED;
		}
		istr >> m_mon2;
		m_mon = m_mon2;
		if (m_readErrorCode == NO_ERROR){
			if (istr.get() != '/'){
				m_readErrorCode = CIN_FAILED;
			}
		}
		istr >> m_day2;
		m_day = m_day2;
		if (m_readErrorCode == NO_ERROR)
		if (m_year > MAX_YEAR || m_year < MIN_YEAR){
			m_readErrorCode = YEAR_ERROR;	
			istr.setstate(std::ios::failbit);
		}
		if (m_readErrorCode == NO_ERROR)
		if (m_mon >12 || m_mon < 1){
			m_readErrorCode = MON_ERROR;
			istr.setstate(std::ios::failbit);
		}
		if (m_readErrorCode == NO_ERROR){
			if (m_day < 1 || m_day > mdays()){
				m_readErrorCode = DAY_ERROR;
				istr.setstate(std::ios::failbit);
			}
		}
		
	
	  if (m_dateOnly == false){
		  if (istr.get() != ',')
		  if (istr.get() != ' ')
		  {
			  m_readErrorCode = CIN_FAILED;
		  }
		  istr >> m_hour;
		  if (m_readErrorCode == NO_ERROR)
		  if (m_readErrorCode == NO_ERROR){
			  if (istr.get() != ':'){
				  m_readErrorCode = CIN_FAILED;
			  }
			  if (m_readErrorCode == NO_ERROR)
			  if (m_hour < 1 || m_hour > 24){
				  m_readErrorCode = HOUR_ERROR;
			  }
		  }
		  istr >> m_min;
		  if (m_readErrorCode == NO_ERROR)
		  if (m_readErrorCode == NO_ERROR)
		  if (m_min < 1 || m_min > 59){
			  m_readErrorCode = MIN_ERROR;
		  }
	  }
	  return istr;
  }
  std::ostream& Date::write(std::ostream& ostr)const{
	  ostr << m_year << "/"; 
	  if (m_mon < 10) ostr << "0";
	  ostr << m_mon << "/";
	  if (m_day < 10) ostr << "0";
	  ostr << m_day;
	  if (!m_dateOnly)
		  ostr << ", " << m_hour << ":" << m_min;
	 
	  return ostr;
  }
  std::istream& operator>>(std::istream& is, Date& obj){
	  return obj.read(is);
  }
  std::ostream& operator<<(std::ostream& os, const Date& obj){
	  return obj.write(os);
  }
}
