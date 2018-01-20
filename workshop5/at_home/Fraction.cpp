#include "Fraction.h"

using namespace std;

namespace sict{
	Fraction::Fraction(){
		denom = -1;              // safe empty state
	}

	Fraction::Fraction(int n, int d) // n: numerator, d: denominator
	{
		if (n >= 0 && d > 0){
			num = n;
			denom = d;
			reduce();
		}
		else
			denom = -1;              // set to safe empty state
	}

	int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
	{
		int mn = min();                                        // min of num and denom
		int mx = max();                                        // mX of num and denom

		for (int x = mn; x > 0; x--)                           // find the greatest common divisor
		if (mx % x == 0 && mn % x == 0)
			return x;
		return 1;

	}

	void Fraction::reduce()                                         // simplify the Fraction number  
	{
		int tmp = gcd();
		num /= tmp;
		denom /= tmp;
	}

	int Fraction::max()
	{
		return (num >= denom) ? num : denom;
	}

	int Fraction::min()
	{
		return (num >= denom) ? denom : num;
	}

	// TODO: Copy-paste the implementation of member isEmpty function from the in_lab part answer HERE
	bool Fraction::isEmpty() const{
		return (this->denom == -1);
	}


	// TODO: Copy-paste the implementation of member display function from the in_ab part answer HERE
	void Fraction::display() const{
		if (isEmpty() == false){
			cout << num;
			if (denom != 1)
				cout << "/" << denom;
		}
		else
			cout << "Invalid Fraction Object!";

	}


	// TODO: Copy-paste the implementation of member operator+= function from the in_lab part answer HERE
	Fraction& Fraction::operator+=(Fraction var){
		if (isEmpty() == false && var.isEmpty() == false){
			
			*this = *this + var;
			//var += *this;
			this->reduce();

		}
		return *this;
	}

	// TODO: Copy-paste the implementation of member operator+ function from the in_ab part answer HERE
	Fraction Fraction::operator+(Fraction var){
		Fraction temp(1, -1);
		if (isEmpty() == false && var.isEmpty() == false){
			temp.num = ((num*var.denom) + (var.num*denom));
			temp.denom = (denom*var.denom);
		}
		return temp;
	}

	// TODO: Copy-paste the implementation of member operator* function from the in_lab part answer HERE
	Fraction Fraction::operator*(Fraction var){
		Fraction temp(1, -1);
		if (isEmpty() == false && var.isEmpty() == false){
			temp.num = this->num * var.num;
			temp.denom = this->denom * var.denom;
		}
		return temp;
	}


	// TODO: write the implementation of member operator== function HERE

	bool operator==(Fraction left, Fraction right){
		

		return (left.denom == -1 || right.denom == -1) ? false : left.num*right.denom == left.denom*right.num;

			
	}

	// TODO: write the implementation of member operator!= function HERE
	bool operator!=(Fraction left, Fraction right){
		return (left.denom == -1 || right.denom == -1) ? false : left.num*right.denom != left.denom * right.num;
	}

	// TODO: write the implementation of member operator int () function HERE
	Fraction::operator int(){
		return (denom == -1) ? (-1.0) : (int(num)/denom);
	}

	// TODO: write the implementation of member operator double () function HERE
	Fraction::operator double(){
		return (denom == -1) ? (-1.0) : (double(num)/denom);
		
	}


}