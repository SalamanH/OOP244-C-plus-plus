#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
#include <fstream>
#include <iostream>
#include "Date.h"
#include "NonPerishable.h"
#include <iomanip>
namespace ict {
	class Perishable : public NonPerishable {
		Date m_expiry;
	protected:
		char signature()const;
		
	public:
		Perishable();
		virtual std::fstream& save(std::fstream& file)const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& ostr, bool l)const;
		virtual std::istream& read(std::istream& istr);
//		istr.setstate(ios::failbit);
	};


}


#endif
