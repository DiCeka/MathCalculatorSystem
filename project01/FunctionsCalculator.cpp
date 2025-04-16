#pragma once
#include "Calculators.h"
#include <iostream>
#include "iotools.h"
#include <string>

using namespace std;
void FunctionsCalculator(bool &isexecuting)
{
	string polynomial_title = "1) Полином степени N (a, N - пользовательские значения)\na0 + a1*x + a2*x^2 + .... + aN*x^N;\n\n";
	string power_title = "2) Степенная (a, b, c - пользовательские значения)\na * b^(c*x)+d;\n\n";
	string exponental_title = "3) Показательная (a, b, c, d - пользовательские значения)\na * b^(c*x)+d;\n\n";
	string logariphmic_title = "4) Логарифмическая (a, b, c - пользовательские значения)\na * Ln(b*x) + c\n\n";
	string sin_title = "5) Синусоида (a, b, c, d - пользовательские значения)\na*sin(b*x + c) + d;\n\n";
	string cos_title = "6) Косинусоида (a, b, c, d - пользовательские значения)\na*cos(b*x + c) + d;\n\n\n\n";

	string TITLES[6] = { polynomial_title, power_title, exponental_title, logariphmic_title, sin_title, cos_title };

	system("cls");
	cout << "КАЛЬКУЛЯТОР ФУНКЦИЙ\n\n";
	cout << "Перечень допустимых функций: \n\n";

	for (int i = 0; i < 6; i++) cout << TITLES[i];
	
	int selection = iotools_Int_InputInOutRange("Введите номер нужной функции (1-6): ", "Ошибка!", 1, 6, 3);

	system("cls"); cout << "Выбрана функция: \n" << TITLES[selection - 1];




//запрос выйти в меню или продолжить этот калькулятор
	CycleRequest(isexecuting);

}

