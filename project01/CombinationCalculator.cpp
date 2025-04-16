#pragma once
#include "Calculators.h"
#include "iotools.h"
void CombinationCalculator(bool& isexecuting)
{
	system("cls");//чистим консоль при каждой итерации калькулятора (для красоты и стиля)

	//главный код калькулятора


//запрос выйти в меню или продолжить этот калькулятор
	CycleRequest(isexecuting);
}