#include "CreditCard.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sict {

	void CreditCard::name(const char cardHolderName[]){
		strcpy(m_cardHolderName,cardHolderName);
	}
	void CreditCard::initialize(
		unsigned long long creditCardNumber,
		int instCode,
		int expiryYear,
		int expiryMonth,
		int numberInTheBack){

		m_cardNumber = creditCardNumber;
		m_institutionCode = instCode;
		m_expiryMonth = expiryMonth;
		m_expiryYear = expiryYear;
		m_numberInTheBack = numberInTheBack; 

	}
	void CreditCard::write(bool displayName, bool displayCardInfo) const{
		
		//if (isValid()){
		if (displayName == true && displayCardInfo == true){
			writeName();
			cout << endl;
			writeCardInfo();
		}
		if (displayName == false && displayCardInfo == true)
			writeCardInfo();
		if (displayName == true && displayCardInfo == false)
			writeName();
		if (displayName == false && displayCardInfo == false){}
			
			/*cout << "Cardholder: " << m_cardHolderName << endl
				<< "Card Number: " << m_cardNumber << endl
				<< "Institution: " << m_institutionCode << endl
				<< "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl
				<< "Number at the back: " << m_numberInTheBack;*/

		//}
	}
	bool CreditCard::isValid() const{
		int num = 0;
		if (strlen(m_cardHolderName) > 0)
			num++;
		if (m_cardNumber >= MIN_CARD_NUMBER && m_cardNumber <= MAX_CARD_NUMBER)
			num++;
		if (m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR)
			num++;
		if (m_expiryMonth >= 1 && m_expiryMonth <= 12)
			num++;
		if (m_numberInTheBack > 0 && m_numberInTheBack < 1000)
			num++;
		if (num == 5)
			return true;
		else
			return false;
	
	}

	void CreditCard::writeName() const{
		cout << "Cardholder: " << m_cardHolderName;
	}
	void CreditCard::writeCardInfo() const{
		cout << "Card Number: " << m_cardNumber << endl
			<< "Institution: " << m_institutionCode << endl
			<< "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl
			<< "Number at the back: " << m_numberInTheBack;
	}

	/*void write(false) const{
		writeCardInfo();
	}
	void write(true, false) const{
		writeName();
	}
	void write(false, false) const{}*/

}