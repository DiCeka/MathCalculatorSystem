#pragma once
#include "Calculators.h"
#include <iostream>
#include "iotools.h"
#include "Matrix.h"
using namespace std;

void MatrCalculator(bool &isexecuting)
{
	
	cout << "МАТРИЧНЫЙ КАЛЬКУЛЯТОР\n\n";
	
	cout << "Выберите желаемую функцию:\n\n";
	cout << " 1 - Сложение/вычитание матриц\n 2 - Вычитание матриц\n \
3 - Умножение матриц\n 4 - Умножение матрицы на число\n \
5 - Сложение матрицы с числом\n 6 - Вычитание из матрицы числа\n \
7 - Транспонирование матрицы\n 8 - Нахождение обратной матрицы\n \
9 - Нахождение определителя матрицы\n";
	
	int selecter = iotools_Int_InputInOutRange("", "Неверный ввод, попробуйте снова", 1, 9, 3);
	
	bool is_executing = true;

	while (is_executing)
	{
		system("cls");	
		switch (selecter)
		{
		case 1: MatrixSum(is_executing); break;
		case 2: MatrixRaznost(is_executing); break;
		}
	}
		
	//запрос выйти в меню или продолжить этот калькулятор
	CycleRequest(isexecuting);
}
