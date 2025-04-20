#pragma once
#include "FUNC_OPERATIONS.h"
#include "FUNC_DATA_MAIN.h"

#include <iostream>
using namespace std;
string defined_integral_operation_title = "1 - Вычислить определённый интеграл на отрезке\n\n";
string graph_generation_operation_title = "2 - Построение и визуализация графика\n\n";
string root_determination_operation_title = "3 - Поиск корня (y = 0) на отрезке\n\n";
string extremes_determination_operation_title = "4 - Поиск экстремумов на отрезке\n\n";

string OPERATIONS[4] = { defined_integral_operation_title, graph_generation_operation_title,
	root_determination_operation_title, extremes_determination_operation_title };



void FUNC_EXTREMES_DEFINITIVE(float f(float), float a, float b) {
	float x1 = a;
	float x2 = x1 + STEP;
	float x3 = x2 + STEP;

	while (x3 <= b) {
		float y1 = f(x1);
		float y2 = f(x2);
		float y3 = f(x3);

		if ((y2 > y1 && y2 > y3) || (y2 < y1 && y2 < y3)) {
			cout << "Экстремум в x = " << x2 << ", f(x) = " << y2;
			if (y2 > y1 && y2 > y3)
				cout << " -> максимум\n";
			else
				cout << " -> минимум\n";
		}

		x1 = x2;
		x2 = x3;
		x3 += STEP;
	}
}



float FUNC_INTEGRATE_CALCULATIOn(float (*func)(float), float a, float b, int n) {
	float h = (b - a) / n;
	float sum = 0.5 * (func(a) + func(b));

	for (int i = 1; i < n; ++i) {
		sum += func(a + i * h);
	}
	return sum * h;
}

float FUNC_GET_ROOT(float (*F)(float), float x1, float x2) {
	float mid;
	while ((x2 - x1) > APROXIMATY) {
		mid = (x1 + x2) / 2.0;
		if (F(x1) * F(mid) <= 0)
			x2 = mid;
		else
			x1 = mid;
	}
	return (x1 + x2) / 2.0;

}

int FUNC_PROCEDURAL_ROOTS_EVALUATION(float (*f)(float), float start, float end, float step, float* roots, int maxRoots) {
	float x1 = start;
	float x2 = start + step;
	int count = 0;

	while (x2 <= end && count < maxRoots) {
		if (f(x1) * f(x2) <= 0) {
			float root = FUNC_GET_ROOT(f, x1, x2);
			roots[count++] = root;
		}
		x1 = x2;
		x2 += step;
	}


	return count;
}
