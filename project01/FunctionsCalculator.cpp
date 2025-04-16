#pragma once
#include "Calculators.h"
#include <iostream>
#include "iotools.h"

using namespace std;
void FunctionsCalculator(bool &isexecuting)
{
	system("cls");
	cout << "ÐÀÁÎÒÀ Ñ ÔÓÍÊÖÈßÌÈ\n";

	int a; cin >> a;
	if (a == 1) isexecuting = false;

}

