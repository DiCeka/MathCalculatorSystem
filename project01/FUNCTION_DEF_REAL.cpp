#pragma once
#include <iostream>
#include <string>
#include "FUNC_DATA_MAIN.h"
#include "iotools.h"
using namespace std;
//определение
string polynomial_title = "1 - Полином степени N\n  a0 + a1*x + a2*x^2 + .... + aN*x^N;\n\n";
string power_title = "2 - Степенная функция\n  a * x^b + c;\n\n";
string exponental_title = "3 - Показательная функция\n  a * b^(c*x)+d;\n\n";
string logariphmic_title = "4 - Логарифмическая функция\n  a * Ln(b*x) + c\n\n";
string sin_title = "5 - Синусоида\n  a*sin(b*x + c) + d;\n\n";
string cos_title = "6 - Косинусоида\n  a*cos(b*x + c) + d;\n\n";
string exit_title = "0 - Выход в главное меню\n\n\n\n";

string TITLES[7] = { polynomial_title, power_title, exponental_title,
		logariphmic_title, sin_title, cos_title, exit_title };

int* POLYNOMUS_PARAMS_FILLMENT() {
	int* p = new int[parameters[4]];
	for (int i = 0; i < parameters[4]; i++) {
		string h = "Введите a" + to_string(i) + ": ";
		int aN = iotools_Int_Input(h, "Ошибочный ввод!", 3);
		p[i] = aN;
	}
	return p;
}
float POLYNOMUS_FUNC(float x) {
	float polSum = 0;
	for (int i = 0; i < parameters[4]; i++) {
		if (i == 0) polSum += params_a[i];
		if (i == 1) polSum += params_a[i] * x;
		if (i > 1) polSum += params_a[i] * pow(x, i);
	}

	return polSum;
}
float POW_FUNC(float x) {
	if (x == 0 && parameters[1] <= 0) return 0;
	return parameters[0] * pow(x, parameters[1]) + parameters[2];
}
float EXP_FUNC(float x) {
	if (parameters[1] <= 0 || parameters[1] == 1) return 0;
	return parameters[0] * pow(parameters[1], parameters[2] * x) +
		parameters[3];
}
float LOG_FUNC(float x) {
	if (x <= 0 || parameters[1] <= 0) return 0;
	return parameters[0] * log(parameters[1] * x) + parameters[2];
}
float SIN_FUNC(float x) {
	return (parameters[0] * 1.0) * sin(parameters[1] * x * 1.0 + parameters[2]) + parameters[3];
}
float COS_FUNC(float x) {
	return (parameters[0] * 1.0) * cos(parameters[1] * x * 1.0 + parameters[2]) + parameters[3];
}

float(*funcPTRS[])(float) = { &POLYNOMUS_FUNC,&POW_FUNC, &EXP_FUNC, &LOG_FUNC, &SIN_FUNC, &COS_FUNC };