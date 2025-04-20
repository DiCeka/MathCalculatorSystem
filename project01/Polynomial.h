#pragma once
#include <math.h>
#include <iostream>
#include <locale.h>
#include <malloc.h>

double* InputPolynomial(int degree);

void OutputPolynomial(const double* a, int degree);

double* AdditionOfPolynomials(double* a, double* b);

double* SubtractionOfPolynomials(double* a, double* b);

double* MultiplyingPolynomials(double* a, double*b);

double* MultiplyingApolynomialByANumber(double*a,int degree, double number);

//void DerivativeOfAPolynomial();
//
//void ColumnDivisionOfPolynomials();