#pragma once
#include "Calculators.h"
#include <iostream>
#include "iotools.h"
using namespace std;

void MatrCalculator(bool &isexecuting)
{
	system("cls");//чистим консоль при каждой итерации калькулятора (для красоты и стиля)

		//главный код калькулятора
		
		
	//запрос выйти в меню или продолжить этот калькулятор
	CycleRequest(isexecuting);
}
