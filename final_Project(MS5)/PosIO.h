#pragma once
#ifndef ICT_PosIO_H__
#define ICT_PosIO_H__
#include <fstream>
#include <iostream>
namespace ict {

	class PosIO {
	public:
		virtual std::fstream& save(std::fstream& file)const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& ostr, bool l)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		//std::ostream& write(std::ostream& ostr = std::cout)const;
		//std::istream& read(std::istream& istr = std::cin);
	};
}





#endif