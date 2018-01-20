#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <iostream>
#include <cstring>
// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"
#include "PosIO.h"
using namespace std;
namespace ict {
	// class Item implementaion
	Item::Item() {
		name(nullptr);
		sku("");
		name("");
		price(0);
		taxed(true);
		quantity(0);
	}
	Item::Item(const char* a_sku, const char* a_name, double a_price, bool a_taxed) {
		name(nullptr);
		sku(a_sku);
		name(a_name);
		price(a_price);
		taxed(a_taxed);
		quantity(0);
	}
	Item::Item(const Item& obj) {
		name(nullptr);
		strncpy(m_sku, obj.m_sku, MAX_SKU_LEN);
		m_sku[MAX_SKU_LEN] = '\0';
		name(obj.m_name);
		price(obj.m_price);
		taxed(obj.m_taxed);
		quantity(obj.m_quantity);
	}
	Item::~Item() {
		delete[] m_name;
	}

	void Item::sku(const char* var) {
		strncpy(m_sku, var, MAX_SKU_LEN);
		m_sku[MAX_SKU_LEN] = '\0';

	}
	void Item::price(double var) {
		m_price = var;
	}
	void Item::name(const char* var) {
		
		if (var == nullptr)
			m_name = nullptr;
		else {
			delete[] m_name;
			m_name = new char[strlen(var) + 1];
			strcpy(m_name, var);
		}
	}
	void Item::taxed(bool var) {
		m_taxed = var;
	}
	void Item::quantity(int var) {
		m_quantity = var;
	}

	const char* Item::sku()const {
		return m_sku;
	}
	double Item::price()const {
		return m_price;
	}
	const char* Item::name()const {
		return m_name;
	}
	bool Item::taxed()const {
		return m_taxed;
	}
	int Item::quantity()const {
		return m_quantity;
	}
	
	double Item::cost()const{
		/*double result;
		if (taxed() == true)
			result = m_price * TAX;
		else
			result = m_price;
		return result;*/
		return (taxed() == true) ? (m_price * TAX) + m_price : m_price;
	}
	bool Item::isEmpty(){
		return(	m_sku[0] == '\0' &&	strcmp(m_name, "") == 0 &&	m_price == 0 &&
			m_taxed == false &&	m_quantity == 0	) ? true : false;
	}
	Item& Item::operator=(const Item& obj){
		sku(obj.m_sku);
		price(obj.m_price);
		name(obj.m_name);
		taxed(obj.m_taxed);
		quantity(obj.m_quantity);
		return *this;
	}
	bool const Item::operator==(const char* string){
		return(strcmp(m_sku, string) == 0);
	}
	int Item::operator+=(int var){
		return m_quantity += var;
	}
	int Item::operator-=(int var){
		return m_quantity -= var;
	}

	//std::ostream& Item::write(std::ostream& ostr)const{}
	//std::istream& Item::read(std::istream& istr){}

	// non-member functions

	double operator+=(double& d, const Item& I){
		int temp = I.quantity();
		double temp2 = I.price();
		d += (temp * temp2) * ((I.taxed()) ? (1 + TAX) : 1);;
		return d;
	}
	// operator << and operator >>
	std::istream& operator>>(std::istream& istr, Item& obj){
		obj.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Item& obj){
		obj.write(ostr, true);
		return ostr;
	}

}