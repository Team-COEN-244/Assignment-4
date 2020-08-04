/* Mélina Deneuve ID#40153103
   Rudy Zoghaib   ID#40025399
Assignment - 4 - COEN 244
Environment : Visual Studio 2019 */

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
