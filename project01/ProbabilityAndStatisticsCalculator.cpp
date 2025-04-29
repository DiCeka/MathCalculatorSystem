#pragma once
#include "Calculators.h"
#include "iotools.h"
#include <iostream>
#include <cmath>
#include <conio.h>
#ifdef _WIN32
#define CLEAR "cls"
#define WAIT _getch()
#else
#define CLEAR "clear"
#define WAIT cin.ignore(); cin.get()
#endif
using namespace std;
static void clearScreen() {
    system(CLEAR);
}
static void clearInputBuffer() {
    cin.clear();
    while (cin.get() != '\n') {}  
}
void show_probability_menu() {
    cout << "*******************************\n";
    cout << "* ТЕОРИЯ ВЕРОЯТНОСТЕЙ И СТАТИСТИКА *\n";
    cout << "*******************************\n";
    cout << "* 1. Вероятность события     *\n";
    cout << "* 2. Математическое ожидание *\n";
    cout << "* 3. Дисперсия               *\n";
    cout << "* 0. Выход в меню            *\n";
    cout << "*******************************\n";
    cout << "Выберите операцию (0-3): ";
}
void show_result(const string& result) {
    cout << "\nРезультат: " << result << "\n";
    cout << "Нажмите любую клавишу для продолжения...";
    WAIT;
    clearScreen();
}
void StatisticsCalculator(bool& isexecuting) {
    while (true) {
        clearScreen();
        show_probability_menu();
        int choice;
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 3) {
            clearInputBuffer();
            cout << "Ошибка! Введите число от 1 до 4. Нажмите любую клавишу...";
            WAIT;
            continue;
        }
        if (choice == 0) isexecuting = false; break;
        clearScreen();
        switch (choice) {
        case 1: {
            int m, n;
            cout << "Введите число благоприятных исходов (m): ";
            while (!(cin >> m)) {
                clearInputBuffer();
                cout << "Ошибка! Введите целое число. Нажмите любую клавишу...";
                WAIT;
                clearScreen();
                cout << "Введите число благоприятных исходов (m): ";
            }
            cout << "Введите общее число исходов (n): ";
            while (!(cin >> n) || n <= 0) {
                clearInputBuffer();
                if (n <= 0) {
                    cout << "Ошибка! Число должно быть > 0. Нажмите любую клавишу...";
                }
                else {
                    cout << "Ошибка! Введите целое число. Нажмите любую клавишу...";
                }
                WAIT;
                clearScreen();
                cout << "Введите общее число исходов (n): ";
            }
            double p = static_cast<double>(m) / n;
            show_result("Вероятность: " + to_string(m) + "/" + to_string(n) + " = " + to_string(p));
            break;
        }
        case 2: {
            int size;
            cout << "Введите количество значений: ";
            while (!(cin >> size) || size <= 0) {
                clearInputBuffer();
                if (size <= 0) {
                    cout << "Ошибка! Число должно быть > 0. Нажмите любую клавишу...";
                }
                else {
                    cout << "Ошибка! Введите целое число. Нажмите любую клавишу...";
                }
                WAIT;
                clearScreen();
                cout << "Введите количество значений: ";
            }
            double* values = new double[size];
            double* probs = new double[size];
            double sum = 0;
            for (int i = 0; i < size; i++) {
                clearScreen();
                cout << "Значение " << i + 1 << ": ";
                while (!(cin >> values[i])) {
                    clearInputBuffer();
                    cout << "Ошибка! Введите число. Нажмите любую клавишу...";
                    WAIT;
                    clearScreen();
                    cout << "Значение " << i + 1 << ": ";
                }
                cout << "Вероятность " << i + 1 << ": ";
                while (!(cin >> probs[i]) || probs[i] < 0) {
                    clearInputBuffer();
                    if (probs[i] < 0) {
                        cout << "Ошибка! Вероятность должна быть ≥ 0. Нажмите любую клавишу...";
                    }
                    else {
                        cout << "Ошибка! Введите число. Нажмите любую клавишу...";
                    }
                    WAIT;
                    clearScreen();
                    cout << "Вероятность " << i + 1 << ": ";
                }
                sum += probs[i];
            }
            if (fabs(sum - 1.0) > 1e-6) {
                cout << "Ошибка! Сумма вероятностей должна быть равна 1.0. Нажмите любую клавишу...";
                delete[] values;
                delete[] probs;
                WAIT;
                break;
            }
            double expectation = 0;
            for (int i = 0; i < size; i++) {
                expectation += values[i] * probs[i];
            }
            show_result("Математическое ожидание: " + to_string(expectation));
            delete[] values;
            delete[] probs;
            break;
        }
        case 3: {
            break;
        }
        }
    }

    CycleRequest(isexecuting);
    clearScreen();
}