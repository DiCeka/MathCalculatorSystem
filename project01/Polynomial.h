#pragma once
#include <math.h>
#include <iostream>
#include <locale.h>
#include <malloc.h>

double* InputPolynomial(int degree);

void OutputPolynomial(const double* a, int degree);

double* AdditionOfPolynomials(double* a, double* b);

//void SubtractionOfPolynomials();
//
//void MultiplyingPolynomials();
//
//void MultiplyingApolynomialByANumber();
//
//void DerivativeOfAPolynomial();
//
//void ColumnDivisionOfPolynomials();