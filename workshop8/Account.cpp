#include <iostream>
#include "Account.h"

using namespace std;

namespace ict{

	// constructor   
	Account::Account(){
		balance = 1.0;
	}
	Account::Account(double balance_Initial){
		if (balance_Initial >= 0)
			balance = balance_Initial;
		else
			balance = 1.0;
	}

	// credit (add) an amount to the account balance
	void Account::credit(double add){
		balance += add;
	}

	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double withdraw){
		bool result = false;
		if (balance > withdraw){
			balance -= withdraw;
			result = true;
		}
		return result;
	}

	double Account::getBalance() const
	{
		return balance;
	}

	void Account::setBalance(double newBalance)
	{
		balance = newBalance;
	}
}