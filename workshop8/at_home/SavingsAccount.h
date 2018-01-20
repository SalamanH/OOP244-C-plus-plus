#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
	private:
		double interestRate; // interest rate (percentage)
	public:

		// TODO: put prototypes here
		SavingsAccount(double initial_Balance, double initial_Value);
		double  calculateInterest();
		std::ostream& display(ostream& ostr);
	};
};
#endif