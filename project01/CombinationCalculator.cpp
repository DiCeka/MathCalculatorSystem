#pragma once
#include "ComboCalc.h"
#include "Calculators.h"
#include "iotools.h"
#include <iostream>
using namespace std;

void CombinationCalculator(bool& isexecuting)
{
	system("cls");
	cout << "КАЛЬКУЛЯТОР ФОРМ КОМБИНАТОРИКИ\n\n";	

	cout << "Выберите желаемую функцию:\n\n";
	cout << " 1 - Размещение с повторением\n 2 - Размещение без повторений\n \
3 - Сочетание с повторением\n 4 - Сочетание без повторений\n 5 - Перестановки\n 0 - Выход в главное меню\n";

	int selecter = iotools_Int_InputInOutRange("", "Неверный ввод, попробуйте снова", 0, 5, 3);

	bool is_executing = true;

	while (is_executing)
	{
		system("cls");
		switch (selecter)
		{
		case 1: Razm(1, is_executing); break;
		case 2: Razm(0, is_executing); break;
		case 3: Soch(1, is_executing); break;
		case 4: Soch(0, is_executing); break;
		case 5: Perestanovki(is_executing); break;
		case 0: is_executing = false; isexecuting = false; break;
		}
	}

	CycleRequest(isexecuting, "Выйти в главное меню?");
}