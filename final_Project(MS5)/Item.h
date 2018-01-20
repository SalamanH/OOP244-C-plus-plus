#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include "POS.h"
#include "PosIO.h"
namespace ict{
	// class Item

	class Item : public PosIO {
	private:
		char m_sku[MAX_SKU_LEN + 1];
		char* m_name;
		double m_price;
		bool m_taxed;
		int m_quantity;
	public:
		Item();
		Item(const char* a_sku, const char* a_name, double a_price, bool a_taxed = true); 
		// implement copy construct here
		Item(const Item& obj);
		virtual ~Item();
		//setters
		void sku(const char* var);
		void price(double var);
		void name(const char* var);
		void taxed(bool var);
		void quantity(int var);
		//getters 
		const char* sku()const;
		double price()const;
		const char* name()const;
		bool taxed()const;
		int quantity()const;

		double cost()const;
		bool isEmpty();
		

		//operators
		Item& operator=(const Item& obj);
		const bool operator==(const char* string);
		int operator+=(int var);
		int operator-=(int var);

		std::ostream& write(std::ostream& ostr, bool l)const=0;
	std::istream& read(std::istream& istr)=0;

	};
	// end class Item
	// operator += 
	double operator+=(double& d, const Item& I);
//std::ostream& write(std::ostream& ostr = std::cout)const;
	//	std::istream& read(std::istream& istr = std::cin);
	
	// operator << and operator >>
	std::istream& operator>>(std::istream& istr, Item& obj);
	std::ostream& operator<<(std::ostream& ostr, const Item& obj);
}


#endif