#include "Polynomial.h"
using namespace std;

double* InputPolynomial(int degree) {
	double* a;
	a = (double*)malloc(degree * sizeof(double));

	int number;
	number = degree + 1;

	cout << "Введите " << number << " коэффициента: " << endl;

	for (int i = 0; i <= degree; ++i) {
		cout << "Введите " << i+1 << "-й коэффициент: "; cin >> a[i];
	}

	return a;
}

void AdditionOfPolynomials() {

}

