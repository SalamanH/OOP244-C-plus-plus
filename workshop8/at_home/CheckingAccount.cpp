#include <iostream>

#include "CheckingAccount.h"

using namespace std;

namespace ict {

	// TODO: define CheckingAccount class member functions here  

	CheckingAccount::CheckingAccount(double balance, double fee){
		if (fee < 0) transactionFee = 0;
		else transactionFee = fee;

		setBalance(balance);
	}
	void CheckingAccount::chargeFee(){
		setBalance(getBalance() - transactionFee);
		//return((getBalance() - transactionFee) >= 0) ? true : false;
	}
	bool CheckingAccount::debit(double received){
		if (Account::debit(received))
			chargeFee();
		return(received < getBalance())? true : false;
	}
	void CheckingAccount::credit(double var) {
		Account::credit(var);
		chargeFee();
	}
	std::ostream& CheckingAccount::display(ostream& ostr) {
		return ostr << "Account type: Checking" << endl
			<< "Balance: $ " << getBalance() << endl
			<< "Transaction Fee: " << transactionFee << endl;
		
	}


}