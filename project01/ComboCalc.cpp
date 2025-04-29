#include "ComboCalc.h"



void Razm(int selecter, bool &is_executing)
{
	system("cls");

	int rez;

	if (selecter == 1) cout << "Размещение с повторением\n\n";
	else cout << "Размещение без повторений\n\n";

	int n = iotools_Int_InputInOutRange("Введите количество элементов множества(n): ", "Неверный ввод. Попробуйте снова", 1, INT_MAX, 3);
	eraseline(1);
	cout << "Количество элементов множества(n): " << n << "\n\n";

	int m = iotools_Int_InputInOutRange("Введите количество элементов размещения(m): ", "Неверный ввод. Попробуйте снова", 1, INT_MAX, 3);
	eraseline(1);
	cout << "Количество элементов размещения(m): " << m << "\n\n";

	if (m > n) cout << "ОШИБКА: m не может быть больше n!\n\n";
	else
	{
		if (selecter == 1)
		{
			rez = pow(n, m);
			cout << "Ответ: " << rez << "\n\n";
		}
		else if (selecter == 0)
		{
			rez = fact(n) / fact(n - m);
			cout << "Ответ: " << rez << "\n\n";
		}
	}
	CycleRequest(is_executing);
}

void Soch(int selecter, bool &is_executing)
{
	system("cls");

	int rez;

	if (selecter == 1) cout << "Сочетание с повторением\n\n";
	else cout << "Сочетание без повторений\n\n";

	int n = iotools_Int_InputInOutRange("Введите количество элементов множества(n): ", "Неверный ввод. Попробуйте снова", 1, INT_MAX, 3);
	eraseline(1);
	cout << "Количество элементов множества(n): " << n << "\n\n";

	int m = iotools_Int_InputInOutRange("Введите количество элементов сочетания(m): ", "Неверный ввод. Попробуйте снова", 1, INT_MAX, 3);
	eraseline(1);
	cout << "Количество элементов размещения(m): " << m << "\n\n";

	if (m > n) cout << "ОШИБКА: m не может быть больше n!\n\n";
	else
	{
		if (selecter == 1)
		{
			rez = fact(n + m - 1) / (fact(m) * fact(n - 1));
			cout << "Ответ: " << rez << "\n\n";
		}
		else if (selecter == 0)
		{
			rez = fact(n) / (fact(m) * fact(n - m));
			cout << "Ответ: " << rez << "\n\n";
		}
	}
	CycleRequest(is_executing);
}

void Perestanovki(bool &is_executing)
{
	system("cls");

	cout << "Перестановки\n\n";

	int n = iotools_Int_InputInOutRange("Введите количество элементов(n): ", "Неверный ввод. Попробуйте снова", 1, INT_MAX, 3);
	eraseline(1);
	cout << "Количество элементов(n): " << n << "\n\n";

	cout << "Ответ: " << fact(n) << "\n\n";

	CycleRequest(is_executing);
}
