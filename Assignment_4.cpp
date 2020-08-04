#include <iostream>

#include "RationalNumber.h"

int main()
{
    std::cout << "This program will make calculations with two fractions you will enter" << std::endl;
    RationalNumber Fraction1, Fraction2;
    Fraction1.setRationalNumber();
    Fraction2.setRationalNumber();

    Fraction1 + Fraction2;
    Fraction1 - Fraction2;
    Fraction1 * Fraction2;
    Fraction1 / Fraction2;
    Fraction1 < Fraction2;
    Fraction1 > Fraction2;
    Fraction1 <= Fraction2;
    Fraction1 >= Fraction2;
    Fraction1 == Fraction2;
    Fraction1 != Fraction2;
}
