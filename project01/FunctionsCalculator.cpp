#pragma once
#include "Calculators.h"
#include <iostream>
#include "iotools.h"
#include <string>

using namespace std;
void FunctionsCalculator(bool& isexecuting)
{
	//ВЫБОР ФУНКЦИИ
	string polynomial_title = "1) Полином степени N (a, N - пользовательские значения)\na0 + a1*x + a2*x^2 + .... + aN*x^N;\n\n";
	string power_title = "2) Степенная (a, b, c - пользовательские значения)\na * b^(c*x)+d;\n\n";
	string exponental_title = "3) Показательная (a, b, c, d - пользовательские значения)\na * b^(c*x)+d;\n\n";
	string logariphmic_title = "4) Логарифмическая (a, b, c - пользовательские значения)\na * Ln(b*x) + c\n\n";
	string sin_title = "5) Синусоида (a, b, c, d - пользовательские значения)\na*sin(b*x + c) + d;\n\n";
	string cos_title = "6) Косинусоида (a, b, c, d - пользовательские значения)\na*cos(b*x + c) + d;\n\n\n\n";

	string TITLES[6] = { polynomial_title, power_title, exponental_title, 
		logariphmic_title, sin_title, cos_title };

	system("cls");
	cout << "КАЛЬКУЛЯТОР ФУНКЦИЙ\n\n";
	cout << "Перечень допустимых функций: \n\n";

	for (int i = 0; i < 6; i++) cout << TITLES[i];

	int selection_func = iotools_Int_InputInOutRange("Введите номер нужной функции (1-6): ", "Ошибка!", 1, 6, 3);

	system("cls"); cout << "ВЫБРАНА ФУНКЦИЯ: \n\n" << TITLES[selection_func - 1];
	system("pause");

	//ВЫБОР ОПЕРАЦИИ
	string defined_integral_operation_title = "1) Вычислить определённый интеграл на отрезке [A; B] (пользовательский ввод);\n\n";
	string graph_generation_operation_title = "2) Построение и визуализация графика;\n\n";
	string root_determination_operation_title = "3) Поиск корня (y = 0) на отрезке [A; B] (пользовательский ввод);\n\n";
	string extremes_determination_operation_title = "4) Поиск экстремумов на отрезке [A; B] (пользовательский ввод);\n\n";

	string OPERATIONS[4] = { defined_integral_operation_title, graph_generation_operation_title, 
		root_determination_operation_title, extremes_determination_operation_title};

	system("cls"); cout << "ПЕРЕЧЕНЬ ВОЗМОЖНЫХ ОПЕРАЦИЙ: \n\n";
	for (int i = 0; i < 4; i++) cout << OPERATIONS[i];

	int selection_operation = iotools_Int_InputInOutRange("\nВыберите нужную операцию (1-4): ", "Ошибка!", 1, 4, 4);

	system("cls");
	cout << "ВЫБРАНА ОПЕРАЦИЯ: \n\n" << OPERATIONS[selection_operation - 1] << "\n\n";
	system("pause");

	//РАБОТА С ВЫБРАННЫМИ ПАРАМЕТРАМИ
	system("cls");
	cout << "С ЧЕМ РАБОТАЕМ?\n\n" << TITLES[selection_func - 1].erase(0,3)<< endl;
	cout << "НАД ЧЕМ РАБОТАЕМ?\n\n" << OPERATIONS[selection_operation - 1].erase(0, 3) << endl;
	cout << "\n\nХОД ВЫПОЛНЕНИЯ ОПЕРАЦИИ:\n\n";

	




	//запрос выйти в меню или продолжить этот калькулятор
	CycleRequest(isexecuting);

}

