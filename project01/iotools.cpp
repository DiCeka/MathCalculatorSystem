#pragma once
#include "iotools.h"
#include <iostream>
#include <string>
using namespace std;

void CycleRequest(bool& isexecuting, string question) {

    cout << question << "\n1-ДА\n2-НЕТ\n";
    int selection = iotools_Int_InputInOutRange("", "Такого выбора нет!", 1, 2, 3);
    if (selection == true) { isexecuting = false; system("cls"); }
}

void CinQualification() {
    if (std::cin.fail()) {//если cin не удался
        std::cin.clear(); //очистим ввод
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //проигнорируем все введённое 
    }
}

double iotools_Double_Input(string UserHint, string FailHint, int linesToClear)
{
    double container;
    bool isinvalid;
    do
    {
        isinvalid = false;
        cout << UserHint;
        cin >> container;
        if (cin.fail()) {
            isinvalid = true;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << FailHint << "\n";
            system("pause");
            eraseline(linesToClear);
        }
    } while (isinvalid);
    return container;
}

int iotools_Int_Input(string UserHint, string FailHint, int linesToClear)
{
    int container;
    bool isinvalid;
    do
    {
        isinvalid = false;
        cout << UserHint;
        cin >> container;
        if (cin.fail()) {
            isinvalid = true;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << FailHint << "\n";
            system("pause");
            eraseline(linesToClear);
        }
    } while (isinvalid);
    return container;
}

int iotools_Int_InputInOutRange(std::string UserHint, std::string FailHint, int startRange, int EndRange, int linesToClear, bool flipRange) {
    int container; //записываем сюда все введеное пользователем
    if (!flipRange) { //проверка на ввод В диапазоне
        do { //обрабатываем процесс ввода
            std::cout << UserHint; //выведем на экран сообщение, что надо ввести
            std::cin >> container; //запишем ввод
            CinQualification(); //проведём проверку на ошибочность данных, чтобы программа не сломалась
            if (container < startRange || container > EndRange) { //если введённое значение будет вне диапазона...
                std::cout << FailHint << std::endl; //...выведем ошибку
                system("pause"); //остановим консоль
                eraseline(linesToClear); //удалим нужное количество строк
            }
        } while (container < startRange || container > EndRange); //запрос вввода будет до тех пор, пока не введётся верное (все тесты пройдут успешно)
    }
    else { //проверка на ввод ВНЕ диапазона
        do { //обрабатываем процесс ввода
            std::cout << UserHint; //выведем на экран сообщение, что надо ввести
            std::cin >> container; //запишем ввод
            CinQualification(); //проведём проверку на ошибочность данных, чтобы программа не сломалась
            if (container > startRange || container < EndRange) { //если введённое значение будет В диапазоне...
                std::cout << FailHint << std::endl; //...выведем ошибку
                system("pause"); //остановим консоль
                eraseline(linesToClear); //удалим нужное количество строк
            }
        } while (container > startRange || container < EndRange); //запрос вввода будет до тех пор, пока не введётся верное (все тесты пройдут успешно)
    }

    return container; //вернём итоговое введённое значение
}

double iotools_Double_InputInOutRange(string UserHint, string FailHint, double startRange, double EndRange, int linesToClear, bool flipRange) {
    int container; //записываем сюда все введеное пользователем
    if (!flipRange) { //проверка на ввод В диапазоне
        do { //обрабатываем процесс ввода
            std::cout << UserHint; //выведем на экран сообщение, что надо ввести
            std::cin >> container; //запишем ввод
            CinQualification(); //проведём проверку на ошибочность данных, чтобы программа не сломалась
            if (container < startRange || container > EndRange) { //если введённое значение будет вне диапазона...
                std::cout << FailHint << std::endl; //...выведем ошибку
                system("pause"); //остановим консоль
                eraseline(linesToClear); //удалим нужное количество строк
            }
        } while (container < startRange || container > EndRange); //запрос вввода будет до тех пор, пока не введётся верное (все тесты пройдут успешно)
    }
    else { //проверка на ввод ВНЕ диапазона
        do { //обрабатываем процесс ввода
            std::cout << UserHint; //выведем на экран сообщение, что надо ввести
            std::cin >> container; //запишем ввод
            CinQualification(); //проведём проверку на ошибочность данных, чтобы программа не сломалась
            if (container > startRange || container < EndRange) { //если введённое значение будет В диапазоне...
                std::cout << FailHint << std::endl; //...выведем ошибку
                system("pause"); //остановим консоль
                eraseline(linesToClear); //удалим нужное количество строк
            }
        } while (container > startRange || container < EndRange); //запрос вввода будет до тех пор, пока не введётся верное (все тесты пройдут успешно)
    }

    return container; //вернём итоговое введённое значение
}

int iotools_Int_InputMoreLessThanValue(std::string UserHint, std::string FailHint, int CompareValue, int linesToClear, bool flipQualitification) {
    int container; //записываем сюда все введеное пользователем
    if (!flipQualitification) {//ОБРАБОТКА flipQialification = false, то есть чтоб ввод был БОЛЬШЕ заданного числа
        do { //обрабатываем процесс ввода
            std::cout << UserHint; //выведем на экран сообщение, что надо ввести
            std::cin >> container; //запишем ввод
            CinQualification(); //проведём проверку на ошибочность данных, чтобы программа не сломалась
            if (container < CompareValue) { //если введённое значение будет меньше нужного числа...
                std::cout << FailHint << std::endl; //...выведем ошибку
                system("pause"); //остановим консоль
                eraseline(linesToClear); //удалим нужное количество строк
            }
        } while (container < CompareValue); //запрос вввода будет до тех пор, пока не введётся верное (все тесты пройдут успешно)

    }
    else { //ОБРАБОТКА flipQialification = true, то есть чтоб ввод был МЕНЬШЕ заданного числа
        do { //обрабатываем процесс ввода
            std::cout << UserHint; //выведем на экран сообщение, что надо ввести
            std::cin >> container; //запишем ввод
            CinQualification(); //проведём проверку на ошибочность данных, чтобы программа не сломалась
            if (container > CompareValue) { //если введённое значение будет больше числа...
                std::cout << FailHint << std::endl; //...выведем ошибку
                system("pause"); //остановим консоль
                eraseline(linesToClear); //удалим нужное количество строк
            }
        } while (container > CompareValue); //запрос вввода будет до тех пор, пока не введётся верное (все тесты пройдут успешно)

    }
    return container; //вернём итоговое введённое значение
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
        cout << "\033[1A";
        cout << "\33[2K\r";
    }
}