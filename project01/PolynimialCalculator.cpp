#pragma once
#include "iotools.h"
#include "Calculators.h"
#include "Polynomial.h"
#include <iostream>
#include <string>
using namespace std;

void PolynimialCalculator( bool &isExecuting)
{
	int selecter = iotools_Int_InputInOutRange("Выберете действие с многочленом:\n\t 1 - Сложение многочленов\n\t 2 - Вычитание многочленов\n\t 3 - Умножение многочленов\n\t 4 - Умножение многочлена на число\n\t \
5 - Вычисление производной от многочлена\n\t 6 - Деление многочлена в столбик\n", "ERROR: Такого действия нет!", 1, 6, 10);

	switch (selecter)
	{
	case 1: {
		double* a, * b, * c;
		int a_degree, b_degree;

		cout << "Введите степень первого многочлена: "; cin >> a_degree;

		while (a_degree < 0) {
			cout << "Error! Введено некорректное значение степени многочлена.";
			cout << "Введите степень многочлена: "; cin >> a_degree;
		}

		a = InputPolynomial(a_degree);


		cout << "Введите степень второго многочлена: "; cin >> b_degree;

		while (b_degree < 0) {
			cout << "Error! Введено некорректное значение степени многочлена.";
			cout << "Введите степень многочлена: "; cin >> b_degree;
		}

		b = InputPolynomial(b_degree);

		OutputPolynomial(a, a_degree);
		cout << endl << "+" << endl;
		OutputPolynomial(b, b_degree);
		cout << endl << "=" << endl;
		c = AdditionOfPolynomials(a, b);
		OutputPolynomial(c, max(a_degree, b_degree));

	}; break;

	case 2: {
		double* a, * b, * c;
		int a_degree, b_degree;

		cout << "Введите степень первого многочлена: "; cin >> a_degree;

		while (a_degree < 0) {
			cout << "Error! Введено некорректное значение степени многочлена.";
			cout << "Введите степень многочлена: "; cin >> a_degree;
		}

		a = InputPolynomial(a_degree);
		

		cout << "Введите степень второго многочлена: "; cin >> b_degree;

		while (b_degree < 0) {
			cout << "Error! Введено некорректное значение степени многочлена.";
			cout << "Введите степень многочлена: "; cin >> b_degree;
		}

		b = InputPolynomial(b_degree);

		OutputPolynomial(a, a_degree);
		cout << endl << "-" << endl;
		OutputPolynomial(b, b_degree);
		cout << endl << "=" << endl;
		c = SubtractionOfPolynomials(a, b);
		OutputPolynomial(c, max(a_degree, b_degree));

	}; break;

	//case 3: MultiplyingPolynomials(); break;

	case 4: {
		double* a, * c;
		int a_degree;
		double number;

		cout << "Введите степень многочлена: "; cin >> a_degree;

		while (a_degree < 0) {
			cout << "Error! Введено некорректное значение степени многочлена.";
			cout << "Введите степень многочлена: "; cin >> a_degree;
		}

		a = InputPolynomial(a_degree);

		cout << "Введите число, на которое нужно умножить многочлен: "; cin >> number;

		OutputPolynomial(a, a_degree);
		cout << endl << "*" << endl;
		cout << number;
		cout << endl << "=" << endl;
		c = MultiplyingApolynomialByANumber(a, a_degree, number);
		OutputPolynomial(c, a_degree);

	}; break;
	//case 5: DerivativeOfAPolynomial(); break;
	//case 6: ColumnDivisionOfPolynomials(); break;
	}

	cout << endl;
	CycleRequest(isExecuting);
}