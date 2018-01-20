#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__
#include "Item.h"
#include "Error.h"
#include <iostream>
#include <fstream>
#include <iomanip>
namespace ict {
	class NonPerishable : public Item {
		Error m_err;
	protected:
		bool ok() const;
		void error(const char* message);
		virtual char signature()const;
	public:
		virtual std::fstream& save(std::fstream& file)const ;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& ostr, bool linear)const;
		virtual std::istream& read(std::istream& istr);

		//std::istream& operator >> (std::istream&, NonPerishable&);
		//std::ostream& operator << (std::ostream&, const NonPerishable&);

		/*std::fstream& save(std::fstream& file)const;
		std::fstream& load(std::fstream& file);
		ostream& write(ostream& ostr, bool linear)const;
		std::istream& read(std::istream& is);*/
		//istr.setstate(ios::failbit);


	};

}







#endif