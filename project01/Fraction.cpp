#include "Fraction.h"
// Наибольший общий делитель
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Сокращение дроби
void reduce(Fraction& f) {
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    int d = gcd(f.num, f.den);
    f.num /= d;
    f.den /= d;
}

// Создание дроби
Fraction make_fraction(int n, int d) {
    if (d == 0) {
        cout << "Error: zero denominator!" << endl;
        d = 1;
    }
    Fraction result = { n, d };
    reduce(result);
    return result;
}

// Арифметические операции
Fraction add(Fraction a, Fraction b) {
    Fraction result = {
        a.num * b.den + b.num * a.den,
        a.den * b.den
    };
    reduce(result);
    return result;
}

Fraction subtract(Fraction a, Fraction b) {
    Fraction result = {
        a.num * b.den - b.num * a.den,
        a.den * b.den
    };
    reduce(result);
    return result;
}

Fraction multiply(Fraction a, Fraction b) {
    Fraction result = {
        a.num * b.num,
        a.den * b.den
    };
    reduce(result);
    return result;
}

Fraction divide(Fraction a, Fraction b) {
    if (b.num == 0) {
        cout << "Error: division by zero!" << endl;
        return make_fraction(0);
    }
    Fraction result = {
        a.num * b.den,
        a.den * b.num
    };
    reduce(result);
    return result;
}

// Сравнение
bool equal(Fraction a, Fraction b) {
    return a.num == b.num && a.den == b.den;
}
bool less(Fraction a, Fraction b) {
    return a.num * b.den < b.num * a.den;
}
// Преобразование в десятичную дробь
double to_decimal(Fraction f) {
    return 1.0 * f.num / f.den; ;
}
// Вывод дроби
void print(Fraction f) {
    if (f.den == 1)
        cout << f.num;
    else
        cout << f.num << "/" << f.den;
}