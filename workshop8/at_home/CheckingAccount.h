#pragma once
#ifndef ICT_CHECKINGACCOUNT_H__
#define ICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;
namespace ict {
	class CheckingAccount : public Account {
		double transactionFee;

	public:
		CheckingAccount(double balance, double fee);
		void chargeFee();
		bool debit(double received);
		void credit(double var);
		std::ostream& display(ostream& ostr);
	};
}

#endif
