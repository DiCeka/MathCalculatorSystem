#define FRACTION_H
#include <iostream>
using namespace std;
struct Fraction {
    int num; // числитель
    int den; // знаменатель
};
Fraction make_fraction(int n, int d = 1);
Fraction add(Fraction a, Fraction b);
Fraction subtract(Fraction a, Fraction b);
Fraction multiply(Fraction a, Fraction b);
Fraction divide(Fraction a, Fraction b);
void print(Fraction f);
double to_decimal(Fraction f);