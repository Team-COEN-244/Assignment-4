#include "RationalNumber.h"

// Default constructor
RationalNumber::RationalNumber()
{
	numerator = 1;
	denominator = 2;
}

// Copy-constructor asking the user to enter a certain rational number
void RationalNumber::setRationalNumber()
{
	std::cout << std::endl << "Please enter an integer as the numerator: ";
	std::cin >> numerator;
	std::cout << "Please enter an integer as the denominator: ";
	std::cin >> denominator;
	while (denominator == 0)
	{
		std::cout << "Please 0 is not acceptable for a denominator, enter an other number.";
		std::cin >> denominator;
	}
	getReducedRational(); // Simplification of the fraction
	std::cout << std::endl << "The reduced format of this fraction is: " << toRationalString() << std::endl;
}

// Function that searches for rest of divisions to reduce the fraction
void RationalNumber::getReducedRational()
{
	int rest, num{ numerator }, den{ denominator };

	while (num % den != 0)
	{
		rest = num % den;
		num = den;
		den = rest;
	}
	numerator = numerator / den;
	denominator = denominator / den;
}

// outputs the reduced fraction, if it is an integer, it will output the integer
std::string RationalNumber::toRationalString()
{
	std::string RationalString;
	std::string negative, slash, num, den;

	negative = "- ";
	slash = " / ";
	if (denominator == 1) // It verifies that the numerator or denominator or both are negative or positive 
		RationalString = std::to_string(numerator);
	else
	{
		if (numerator < 0 || denominator < 0)
		{
			num = std::to_string(abs(numerator));
			den = std::to_string(abs(denominator));
			RationalString = negative + num + slash + den; // Then it prints out the result as a negative result
		}
		else if (numerator < 0 && denominator < 0)
		{
			num = std::to_string(abs(numerator));
			den = std::to_string(abs(denominator));
			RationalString = num + slash + den; // It prints out as a positive result (in case of 2 negative integers ad num and den)
		}
		else
		{
			num = std::to_string(numerator);
			den = std::to_string(denominator);
			RationalString = num + slash + den; // nothing is changed when both integers are positive
		}
	}
	return RationalString;
}


void RationalNumber::getcommunDenominator(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	if (Fraction1.denominator != Fraction2.denominator)
	{
		Fraction1.numerator = Fraction1.numerator * Fraction2.denominator;
		Fraction2.numerator = Fraction2.numerator * Fraction1.denominator;
		Fraction1.denominator = Fraction1.denominator * Fraction2.denominator;
		Fraction2.denominator = Fraction1.denominator;
	}
}

// Copy constructor to initialize the result fractions
void RationalNumber::autosetRational(int num, int den)
{
	numerator = num;
	denominator = den;
	getReducedRational();
}


std::ostream& operator+(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	int result_numerator, result_denominator;
	RationalNumber* Result_Fraction = new(RationalNumber);
	Result_Fraction->getcommunDenominator(Fraction1, Fraction2);
	result_numerator = Fraction1.numerator + Fraction2.numerator;
	result_denominator = Fraction1.denominator;

	Result_Fraction->autosetRational(result_numerator, result_denominator);
	return std::cout << std::endl << "The addition's result of both rational numbers is: "
		<< Result_Fraction->toRationalString() << std::endl;
}

std::ostream& operator-(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	int result_numerator, result_denominator;
	RationalNumber* Result_Fraction = new(RationalNumber);
	Result_Fraction->getcommunDenominator(Fraction1, Fraction2);
	result_numerator = Fraction1.numerator - Fraction2.numerator;
	result_denominator = Fraction1.denominator;

	Result_Fraction->autosetRational(result_numerator, result_denominator);
	return std::cout << "The substraction's result of both rational numbers is: "
		<< Result_Fraction->toRationalString() << std::endl;
}

std::ostream& operator*(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	int result_numerator, result_denominator;
	RationalNumber Result_Fraction;
	result_numerator = Fraction1.numerator * Fraction2.numerator;
	result_denominator = Fraction1.denominator * Fraction2.denominator;

	Result_Fraction.autosetRational(result_numerator, result_denominator);
	return std::cout << "The multiplication's result of both rational numbers is: "
		<< Result_Fraction.toRationalString() << std::endl;
}

std::ostream& operator/(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	int result_numerator, result_denominator;
	RationalNumber Result_Fraction;
	result_numerator = Fraction1.numerator * Fraction2.denominator;
	result_denominator = Fraction1.denominator * Fraction2.numerator;

	Result_Fraction.autosetRational(result_numerator, result_denominator);
	return std::cout << "The division's result of both rational numbers is: "
		<< Result_Fraction.toRationalString() << std::endl;
}


std::ostream& operator<(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator < Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " < " << Fraction2.toRationalString()
		<< " is " << verify << std::endl;
}

std::ostream& operator>(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator > Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " > " << Fraction2.toRationalString()
		<< " is " << verify << std::endl;
}

std::ostream& operator<=(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator <= Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " <= " << Fraction2.toRationalString()
		<< " is " << verify << std::endl;
}

std::ostream& operator>=(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator >= Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " >= " << Fraction2.toRationalString()
		<< " is " << verify << std::endl;
}

std::ostream& operator==(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator == Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " == " << Fraction2.toRationalString()
		<< " is " << verify << std::endl;
}

std::ostream& operator!=(RationalNumber& Fraction1, RationalNumber& Fraction2)
{
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator != Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " != " << Fraction2.toRationalString()
		<< " is " << verify << std::endl;
}


// Destructor
RationalNumber::~RationalNumber()
{
	numerator = 0;
	denominator = 1;
}
