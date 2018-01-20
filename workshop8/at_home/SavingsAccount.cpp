#include "SavingsAccount.h"
#include <iostream>
#include <iomanip> 

using namespace std;

namespace ict{

	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double initial_Balance, double initial_Value){
		if (initial_Value > 0){
			interestRate = initial_Value;
			Account::setBalance(initial_Balance);
		}
		else interestRate = 0;
	}
	double  SavingsAccount::calculateInterest(){
		return getBalance() * interestRate;
	}
	std::ostream& SavingsAccount::display(ostream& ostr) {
		std::cout << std::setprecision(2) << std::fixed;
		ostr << "Account type: Saving\nBalance: $ " << getBalance() << "\nInterest Rate (%): " << interestRate * 100 << endl;
		return ostr;
	}
}