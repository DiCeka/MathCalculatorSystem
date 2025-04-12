#pragma once
#include "IOFacility.h"
#include <iostream>
#include <string>
using namespace std;

// Функция проверяет ввод целого числа(int) на корректность, а также на принадлежность к диапазону значений
// от А до В. Если на ввод подается некорректное значение, то программа не завершается аварийно, даже
// если ввели символы, не являющиеся цифрами. Также эта функция стирает строку с неверным вводом дабы не засорять
// командную строку.
// Использует в себе специальные функции sleep() и eraseline()
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

// функция во всём аналогична стандартной функции Sleep(), но использование последней ломает функцию
// проверки ввода InputValidIntRange(), так что для задержки вывода юзаем эту.
void sleep(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	// do nothing until the elapsed time has passed.
	while (clock() < startClock + secondsAhead);
	return;
}

// функция стирает последние n-строк, выведенных в консоль
// На вход принимает n (число строк которое нужно стереть)
void eraseline(int n)
{
	cout << "\33[2K\r";

	for (int i = 0; i < n; i++)
	{
		cout << "\033[1A"; // поднимает курсор на строку вверх
		cout << "\33[2K\r"; // удаляет строку на которой стоит курсор
	}
}
