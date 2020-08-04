#ifndef RATIONALNUMBER_HEADER
#define RATIONALNUMBER_HEADER

#include <iostream>
#include <string>

class RationalNumber
{
	int numerator, denominator;

public:

	RationalNumber();
	void setRationalNumber();
	void getReducedRational();
	std::string toRationalString();

	void getcommunDenominator(RationalNumber&, RationalNumber&);
	void autosetRational(int, int);


	friend std::ostream& operator+(RationalNumber&, RationalNumber&);
	friend std::ostream& operator-(RationalNumber&, RationalNumber&);
	friend std::ostream& operator*(RationalNumber&, RationalNumber&);
	friend std::ostream& operator/(RationalNumber&, RationalNumber&);

	friend std::ostream& operator<(RationalNumber&, RationalNumber&);
	friend std::ostream& operator>(RationalNumber&, RationalNumber&);
	friend std::ostream& operator<=(RationalNumber&, RationalNumber&);
	friend std::ostream& operator>=(RationalNumber&, RationalNumber&);
	friend std::ostream& operator==(RationalNumber&, RationalNumber&);
	friend std::ostream& operator!=(RationalNumber&, RationalNumber&);

	~RationalNumber();
};

#endif // !RATIONALNUMBER_HEADER