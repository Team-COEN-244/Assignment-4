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
	std::cout << std::endl << "The reduced format of this fraction is: " << toRationalString() << std::endl; // Printing the simplified fraction and dealing the negative signs
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

// Outputs the reduced fraction, if it is an integer, it will output the integer
std::string RationalNumber::toRationalString()
{
	std::string RationalString;
	std::string negative, slash, num, den;

	negative = "- ";
	slash = " / ";
	if (denominator == 1) // If the denominator is 1, it is not necessary to print out as a fraction, but an integer
		RationalString = std::to_string(numerator);
	else
	{ // It verifies that the numerator or denominator or both are negative or positive 
		if (numerator < 0 || denominator < 0)
		{
			num = std::to_string(abs(numerator));
			den = std::to_string(abs(denominator));
			RationalString = negative + num + slash + den; // Then it prints out the result as a negative result with negative sign befor the fraction
		}
		else if (numerator < 0 && denominator < 0)
		{
			num = std::to_string(abs(numerator));
			den = std::to_string(abs(denominator));
			RationalString = num + slash + den; // It prints out as a positive result (in case of 2 negative integers ad num and den)
		}
		else
			RationalString = std::to_string(numerator) + slash + std::to_string(denominator); // Nothing is changed since both integers are positive
	}
	return RationalString;
}


void RationalNumber::getcommunDenominator(RationalNumber& Fraction1, RationalNumber& Fraction2) 
{ // Searches for a commun denominator to makes calculations or comparisons easier
	if (Fraction1.denominator != Fraction2.denominator)
	{
		Fraction1.numerator = Fraction1.numerator * Fraction2.denominator;
		Fraction2.numerator = Fraction2.numerator * Fraction1.denominator;
		Fraction1.denominator = Fraction1.denominator * Fraction2.denominator;
		Fraction2.denominator = Fraction1.denominator;
	}
}

// Copy constructor to initialize the result fractions with given datas
void RationalNumber::autosetRational(int num, int den)
{
	numerator = num;
	denominator = den;
	getReducedRational();
}


std::ostream& operator+(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the + operator which will directly print out the result, instead of needing the cout operators in the main file
	int result_numerator, result_denominator;
	RationalNumber* Result_Fraction = new(RationalNumber); // Creating a new object of class RationalNumber which represents the result of the calculation
	Result_Fraction->getcommunDenominator(Fraction1, Fraction2); 
	result_numerator = Fraction1.numerator + Fraction2.numerator;
	result_denominator = Fraction1.denominator;

	Result_Fraction->autosetRational(result_numerator, result_denominator); // Using copy constructor, insitializes the new created fraction with the new calculated values for numerator and denominator
	return std::cout << std::endl << "The addition's result of both rational numbers is: "
		<< Result_Fraction->toRationalString() << std::endl; // Instead of using cout in the main file, the "+" operator will directly give an output to the user
}

std::ostream& operator-(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the - operator which will directly print out the result, instead of needing the cout operators in the main file
	int result_numerator, result_denominator;
	RationalNumber* Result_Fraction = new(RationalNumber); // Creating a new object of class RationalNumber which represents the result of the calculation
	Result_Fraction->getcommunDenominator(Fraction1, Fraction2);
	result_numerator = Fraction1.numerator - Fraction2.numerator;
	result_denominator = Fraction1.denominator;

	Result_Fraction->autosetRational(result_numerator, result_denominator); // Using copy constructor, insitializes the new created fraction with the new calculated values for numerator and denominator
	return std::cout << "The substraction's result of both rational numbers is: "
		<< Result_Fraction->toRationalString() << std::endl; // Instead of using cout in the main file, the "-" operator will directly give an output to the user
}

std::ostream& operator*(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the * operator which will directly print out the result, instead of needing the cout operators in the main file
	int result_numerator, result_denominator;
	RationalNumber Result_Fraction; // Creating a new object of class RationalNumber which represents the result of the calculation
	result_numerator = Fraction1.numerator * Fraction2.numerator;
	result_denominator = Fraction1.denominator * Fraction2.denominator;

	Result_Fraction.autosetRational(result_numerator, result_denominator); // Using copy constructor, insitializes the new created fraction with the new calculated values for numerator and denominator
	return std::cout << "The multiplication's result of both rational numbers is: "
		<< Result_Fraction.toRationalString() << std::endl; // Instead of using cout in the main file, the "*" operator will directly give an output to the user
}

std::ostream& operator/(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the / operator which will directly print out the result, instead of needing the cout operators in the main file
	int result_numerator, result_denominator;
	RationalNumber Result_Fraction; // Creating a new object of class RationalNumber which represents the result of the calculation
	result_numerator = Fraction1.numerator * Fraction2.denominator;
	result_denominator = Fraction1.denominator * Fraction2.numerator;

	Result_Fraction.autosetRational(result_numerator, result_denominator); // Using copy constructor, insitializes the new created fraction with the new calculated values for numerator and denominator
	return std::cout << "The division's result of both rational numbers is: "
		<< Result_Fraction.toRationalString() << std::endl; // Instead of using cout in the main file, the "/" operator will directly give an output to the user
}


std::ostream& operator<(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the < comparison operator which will directly print out the result, instead of needing the cout operators in the main file
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator < Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " < " << Fraction2.toRationalString()
		<< " is " << verify << std::endl; // Instead of using cout in the main file, the "<" operator will directly give an output to the user
}

std::ostream& operator>(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the > comparison operator which will directly print out the result, instead of needing the cout operators in the main file
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator > Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " > " << Fraction2.toRationalString()
		<< " is " << verify << std::endl; // Instead of using cout in the main file, the ">" operator will directly give an output to the user
}

std::ostream& operator<=(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the <= comparison operator which will directly print out the result, instead of needing the cout operators in the main file
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator <= Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " <= " << Fraction2.toRationalString()
		<< " is " << verify << std::endl; // Instead of using cout in the main file, the "<=" operator will directly give an output to the user
}

std::ostream& operator>=(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the >= comparison operator which will directly print out the result, instead of needing the cout operators in the main file
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator >= Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " >= " << Fraction2.toRationalString()
		<< " is " << verify << std::endl; // Instead of using cout in the main file, the ">=" operator will directly give an output to the user
}

std::ostream& operator==(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the == comparison operator which will directly print out the result, instead of needing the cout operators in the main file
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator == Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " == " << Fraction2.toRationalString()
		<< " is " << verify << std::endl; // Instead of using cout in the main file, the "==" operator will directly give an output to the user
}

std::ostream& operator!=(RationalNumber& Fraction1, RationalNumber& Fraction2)
{ // Overload of the != comparison operator which will directly print out the result, instead of needing the cout operators in the main file
	std::string verify;
	Fraction1.getcommunDenominator(Fraction1, Fraction2);
	Fraction2.getcommunDenominator(Fraction1, Fraction2);
	(Fraction1.numerator != Fraction2.numerator) ? verify = "true" : verify = "false";
	return std::cout << Fraction1.toRationalString() << " != " << Fraction2.toRationalString()
		<< " is " << verify << std::endl; // Instead of using cout in the main file, the "!=" operator will directly give an output to the user
}


// Destructor which assigns the values of 0 and 1 for the numerator and denominator respectively, so that the result number is 0.
RationalNumber::~RationalNumber()
{
	numerator = 0;
	denominator = 1;
}
