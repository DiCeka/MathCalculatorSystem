#include "Polynomial.h"
using namespace std;

double* InputPolynomial(int degree) {
	double* a;
	a = (double*)malloc(degree * sizeof(double));

	int number;
	number = degree + 1;

	cout << "Введите " << number << " коэффициента: " << endl;

	for (int i = 0; i <= degree; ++i) {
		cout << "Введите " << i + 1 << "-й коэффициент: ";
		cin >> a[i];
	}
	return a;
}

void OutputPolynomial(const double* a, int degree) {
	bool flag = true;
	bool flag0 = true;
	for (int i = degree; i >= 0; --i) {
		if (a[i] != 0) {
			flag0 = false;
			if (!flag) {
				cout << " + ";
			}
			cout << a[i] << "x^" << i;
			flag = false;
		}
	}
	if (flag0)
		cout << "0";
}

double* AdditionOfPolynomials(double* a, double* b) {
	double* result;
	int max_degree;

	if (sizeof(a) >= sizeof(b))
		max_degree = sizeof(a);
	else if (sizeof(a) < sizeof(b))
		max_degree = sizeof(b);

	result = (double*)malloc(max_degree * sizeof(double));

	for (int i = 0; i < max_degree; ++i) {
		double coeff1 = (i < sizeof(a)) ? a[i] : 0;
		double coeff2 = (i < sizeof(b)) ? b[i] : 0;
		result[i] = coeff1 + coeff2;
	}

	return result;
}

double* SubtractionOfPolynomials(double* a, double* b) {
	double* result;
	int max_degree;

	if (sizeof(a) >= sizeof(b))
		max_degree = sizeof(a);
	else if (sizeof(a) < sizeof(b))
		max_degree = sizeof(b);

	result = (double*)malloc(max_degree * sizeof(double));

	for (int i = 0; i < max_degree; ++i) {
		double coeff1 = (i < sizeof(a)) ? a[i] : 0;
		double coeff2 = (i < sizeof(b)) ? b[i] : 0;
		result[i] = coeff1 - coeff2;
	}

	return result;
}

double* MultiplyingPolynomials(double* a, double* b) {
	double* result;

	int size;

	size = sizeof(a) + sizeof(b);

	result = (double*)malloc(size * sizeof(double));

	for (int i = 0; i <= sizeof(a); ++i) {
		for (int j = 0; j <= sizeof(b); ++j) {
			result[i + j] += a[i] * b[j];
		}
	}

	return result;
}

double* MultiplyingApolynomialByANumber(double* a, int degree, double number) {
	double* result;

	result = (double*)malloc((degree + 1) * sizeof(double));

	for (int i = 0; i <= degree; i++) {
		result[i] = a[i] * number;
	}
	return result;
}

double* DerivativeOfAPolynomial(double* a, int degree) {
	double* result;

	result = (double*)malloc((degree-1) * sizeof(double));

	for (int i = 1; i <= degree; ++i) {
		result[i-1] = a[i] * i;
	}

	return result;
}

void OutputDerivative(const double* a, int degree) {
	bool flag = true;
	bool flag0 = true;
	for (int i = degree-1; i >= 0; --i) {
		if (a[i] != 0) {
			flag0 = false;
			if (!flag) {
				cout << " + ";
			}
			cout << a[i] << "x^" << i;
			flag = false;
		}
	}
	if (flag0)
		cout << "0";
}
