#pragma once
#include "Calculators.h"
#include "Fraction.h"
#include "iotools.h"
#include <iostream>
#include <conio.h>
#ifdef _WIN32
#define CLEAR "cls"
#define WAIT _getch()
#else
#define CLEAR "clear"
#define WAIT cin.ignore(); cin.get()
#endif
using namespace std;
void show_menu() {
    cout << "**************************\n";
    cout << "*    Калькулятор дробей   *\n";
    cout << "**************************\n";
    cout << "* 1. Сложение             *\n";
    cout << "* 2. Вычитание            *\n";
    cout << "* 3. Умножение            *\n";
    cout << "* 4. Деление              *\n";
    cout << "* 0. Выход                *\n";
    cout << "**************************\n";
    cout << "Выберите операцию (0-4): \n";
}
void clearScreen() {
    system(CLEAR);
}
void show_result_and_wait(Fraction a, Fraction b, Fraction result, char op) {
    cout << "\nРезультат:\n";
    print(a); cout << " " << op << " ";
    print(b); cout << " = ";
    print(result);
    cout << "\nДесятичная форма: " << to_decimal(result) << "\n\n";
    cout << "Нажмите любую клавишу чтобы продолжить...";
    WAIT; 
    clearScreen();  
}
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
Fraction input_fraction(const char* prompt) {
    int num, den;
    cout << prompt;
    while (!(cin >> num >> den) || den == 0) {
        cout << "Ошибка! Введите числитель и знаменатель (знаменатель ≠ 0): ";
        clearInputBuffer();
    }
    return make_fraction(num, den);
}
void FractionCalculator(bool& isexecuting)
{
	system("cls");
    int choice;
    while (true) {
        show_menu();
        while (!(cin >> choice) || choice < 0 || choice > 4) {
            cout << "Некорректный ввод. Введите число от 0 до 4: ";
            clearInputBuffer();
            system("pause");
            eraseline(2);
        }
        if (choice == 0) { isexecuting = false; break; }
        Fraction a = input_fraction("\nВведите первую дробь (числитель знаменатель): ");
        Fraction b = input_fraction("Введите вторую дробь (числитель знаменатель): ");
        Fraction result;
        char op;
        switch (choice) {
        case 1: result = add(a, b); op = '+'; break;
        case 2: result = subtract(a, b); op = '-'; break;
        case 3: result = multiply(a, b); op = '*'; break;
        case 4:
            if (choice == 4 && b.num == 0) {
                cout << "Ошибка: деление на ноль! Нажмите Enter...";
                cin.ignore();
                cin.get();
                clearScreen();
                continue;
            }
            result = divide(a, b);
            op = '/';
            break;
        }
        clearScreen();
        show_result_and_wait(a, b, result, op);
    }
	CycleRequest(isexecuting);
    clearScreen();
}   