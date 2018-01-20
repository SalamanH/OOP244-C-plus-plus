#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include "NonPerishable.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Date.h"
#include <fstream>

namespace ict {

	bool NonPerishable::ok() const {
		return (m_err == nullptr) ? true : false;
	}
	void NonPerishable::error(const char* message) {
		m_err = message;
	}
	char NonPerishable::signature()const {
		return 'N';
	}

	std::fstream& NonPerishable::save(std::fstream& file)const{
		file << signature() << ',' << sku() << ',' << name() << ',' << price() << ',' << taxed() << ','
			<< quantity();
		/*std::cout << signature() << ',' << sku() << ',' << name() << ',' << price() << ',' << taxed() << ','
			<< quantity() << std::endl;*/
		return file;
	}
	std::fstream& NonPerishable::load(std::fstream& file){
		
		double v_price;
		int v_tax;
		int v_quan;
		char  v_sku[MAX_SKU_LEN];
		char  v_name[80];
		file.getline(v_sku, MAX_SKU_LEN, ',');
		file.getline(v_name, 80, ',');
		file >> v_price;
		file.ignore();
		file >> v_tax;
		file.ignore();
		file >> v_quan;
		

		sku(v_sku);
		name(v_name);
		price(v_price);
		taxed((v_tax == 1)? true : false);
		quantity(v_quan);

		return file;
	}
	std::ostream& NonPerishable::write(std::ostream& ostr, bool linear)const{
		if (ok()){
			if (linear) {
				ostr << std::setw(MAX_SKU_LEN) << std::left << std::setfill(' ') << sku() << '|'
					<< std::setw(20) << std::left << std::setfill(' ') << name() << '|'
					<< std::right << std::setprecision(2) << std::setw(7) << std::fixed << price()
					<< "| ";
				if (taxed()) ostr << "T";
				else ostr << " ";
				ostr << signature() << '|';
				ostr << std::right << std::setw(4) << quantity() << '|';
				ostr << std::right << std::setprecision(2) << std::setw(9) << std::fixed;
				ostr << price() * quantity() * ((taxed()) ? (1 + TAX) : 1) << '|';
			}
			else{
				ostr << "Name:" << std::endl << std::left << name() << std::endl
					<< "Sku: " << sku() << std::endl
					<< "Price: " << price() << std::endl;
				if (taxed())
					ostr << "Price after tax: " << price() * (1 + TAX) << std::endl;
				else 
					ostr << "Price after tax: " << "N/A" << std::endl;
				ostr << "Quantity: " << quantity() << std::endl
					<< "Total Cost: " << std::setprecision(2) << std::fixed << price() * quantity() * ((taxed()) ? (1 + TAX) : 1);
				ostr << std::endl;
			}
		}
		else
			ostr << m_err;

		return ostr;
	}
	std::istream& NonPerishable::read(std::istream& istr){
		double v_price;
		int v_quan;
		char  v_sku[MAX_SKU_LEN];
		char  v_name[80];
		char v_tax;
		m_err.clear();
		std::cout  << "Item Entry:" << std::endl;
		std::cout << "Sku: ";
		istr >> v_sku;
		std::cout << "Name:" << std::endl;
		istr >> v_name;
		std::cout << "Price: ";
		istr >> v_price;
		if (istr.fail() && m_err.isClear())
			m_err = "Invalid Price Entry";
		if (m_err.isClear()){
			std::cout << "Taxed: ";
			istr >> v_tax;
		}
		if ((v_tax != 121 && v_tax != 110) && m_err.isClear()){
			m_err = "Invalid Taxed Entry, (y)es or (n)o";
			istr.setstate(std::ios::failbit);
		}
		if (m_err.isClear()){
			std::cout << "Quantity: ";
			istr >> v_quan;
		}
		if (istr.fail() && m_err.isClear())
			m_err = "Invalid Quantity Entry";
		if (!istr.fail()){
			sku(v_sku);
			name(v_name);
			price(v_price);
			quantity(v_quan);
			taxed((v_tax == 'y') ? true : false);

		}
		return istr;
		
	}

	/*std::istream& operator >> (std::istream&, NonPerishable& n_istr){

	}
	std::ostream& operator << (std::ostream&, const NonPerishable& n_ostr){

	}*/

}