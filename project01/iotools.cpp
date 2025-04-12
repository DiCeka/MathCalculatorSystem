#pragma once
#include "iotools.h"
#include <iostream>
#include <string>
using namespace std;

int InputValidIntRange(int A, int B)
{
	int c, flag;
	do {
		flag = 1;
		cin >> c;
		if (cin.fail()) {
			flag = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Некорректный ввод.";
			sleep(1);
			eraseline(1);
			sleep(0.2);
		}
		else if (c < A || c > B)
		{
			flag = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите число, входящее в диапазон [" << A << ", " << B << "]";
			sleep(1);
			eraseline(1);
			sleep(0.2);
		}
	} while (flag == 0);

	return c;
}

void sleep(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	// do nothing until the elapsed time has passed.
	while (clock() < startClock + secondsAhead);
	return;
}

void eraseline(int n)
{
	cout << "\33[2K\r";

	for (int i = 0; i < n; i++)
	{
		cout << "\033[1A"; // поднимает курсор на строку вверх
		cout << "\33[2K\r"; // удаляет строку на которой стоит курсор
	}
}
