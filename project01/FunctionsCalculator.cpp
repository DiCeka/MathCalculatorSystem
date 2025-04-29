#pragma once
#include "Calculators.h"
#include <iostream>
#include "iotools.h"
#include <string>
#include "SDL.h"
#include "FUNC_DATA_MAIN.h"
#include "FUNCTIONS_DEFINITION.h"
#include "FUNC_OPERATIONS.h"
#include "SDL_WORK.h"
using namespace std;


void FunctionsCalculator(bool& isexecuting)
{
	firstlaunch = true;
	
	system("cls");
	cout << "КАЛЬКУЛЯТОР ФУНКЦИЙ\n\n";
	cout << "Перечень допустимых функций: \n\n";

	for (int i = 0; i < 7; i++) cout << TITLES[i];
	//selection_func = iotools_Int_Input("sf", "sd", 3);
	selection_func = iotools_Int_InputInOutRange("Введите номер нужной функции (0-6): ", "Ошибка!", 0, 6, 3);
	
	if (selection_func == 0) isexecuting = false;
	else
	{

		system("cls"); cout << "ВЫБРАНА ФУНКЦИЯ: \n\n" << TITLES[selection_func - 1].erase(0, 3);
		system("pause");

		system("cls"); cout << "ПЕРЕЧЕНЬ ВОЗМОЖНЫХ ОПЕРАЦИЙ: \n\n";
		for (int i = 0; i < 4; i++) cout << OPERATIONS[i];

		selection_operation = iotools_Int_InputInOutRange("\nВыберите нужную операцию (1-4): ", "Ошибка!", 1, 4, 4);

		system("cls");
		cout << "ВЫБРАНА ОПЕРАЦИЯ: \n\n" << OPERATIONS[selection_operation - 1].erase(0, 3) << "\n\n";
		system("pause");



		//РАБОТА С ВЫБРАННЫМИ ПАРАМЕТРАМИ
		system("cls");
		cout << "С ЧЕМ РАБОТАЕМ?\n\n" << TITLES[selection_func - 1] << endl;
		cout << "НАД ЧЕМ РАБОТАЕМ?\n\n" << OPERATIONS[selection_operation - 1] << endl;


		///!!!!!ХОД ОПЕРАЦИИ!!!!!
		cout << "\n\nХОД ВЫПОЛНЕНИЯ ОПЕРАЦИИ:\n\n";


		//ЗАПОЛНЕНИЕ ДИАПАЗОНА

		int interval_begining = iotools_Int_Input("Введите начало диапазона для x: ", "Неверный ввод!", 3);
		int interval_ending = iotools_Int_InputMoreLessThanValue("Введите конец для диапазона x: ", "Конец не может быть таким", interval_begining, 3);

		cout << "Работаем на интервале [" << interval_begining << "; " << interval_ending << "]\n";

		cout << "\n";
		//ЗАПОЛНЕНИ ПАРАМЕТРОВ a,b,c,d,N


		for (int i = 0; i < VARS_AMOUNT; i++) {
			if (vars_containing_data[selection_func - 1][i] == 1) {
				switch (i)
				{
				case 0: cout << "Введите a: "; break;
				case 1: cout << "Введите b: "; break;
				case 2: cout << "Введите c: "; break;
				case 3: cout << "Введите d: "; break;
				case 4: cout << "Введите N: ";

					break;
				}
				parameters[i] = iotools_Int_Input("", "Неверный ввод!", 3);
				if (i == 4) params_a = POLYNOMUS_PARAMS_FILLMENT();
			}

		}

		float ROOTS[MAX_ROOTS] = { 0.0 };
		int count_roots = 0;

		cout << "\n\n";
		switch (selection_operation) {
		case 1: //интеграл
			cout << "Определённый интеграл от: " << interval_begining << " до " << interval_ending << " равен: " <<
				FUNC_INTEGRATE_CALCULATIOn(funcPTRS[selection_func - 1], interval_begining, interval_ending, INTEGRATION_APPROXIMATY);
			cout << endl;
			break;
		case 2: // график
			GRAPH_VISUALISATOR(funcPTRS[selection_func - 1], interval_begining, interval_ending);
			break;
		case 3: // корни
			count_roots = FUNC_PROCEDURAL_ROOTS_EVALUATION(funcPTRS[selection_func - 1], (float)interval_begining,
				(float)interval_ending, STEP, ROOTS, MAX_ROOTS);

			cout << "Найдено корней: " << count_roots << "\n";
			for (int i = 0; i < count_roots; ++i) {
				cout << ROOTS[i] << "\n";
			}
			cout << endl;
			break;
		case 4: //экстрим
			FUNC_EXTREMES_DEFINITIVE(funcPTRS[selection_func - 1], interval_begining, interval_ending);
			break;

		}
		//GRAPH_VISUALISATOR(funcPTRS[selection_func - 1], interval_begining, interval_ending);
		if (params_a)
			delete[] params_a;

		//запрос выйти в меню или продолжить этот калькулятор
		CycleRequest(isexecuting);
	}
}

