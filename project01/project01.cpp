#include "iotools.h"
#include "MatrCalculator.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    // переменная, предназначенная для выбора пользователем нужного калькулятора
    int selecter;

    cout << "Какой калькулятор хотите использовать?\n\t 1 - Матричный калькулятор\n\t 2 - Калькулятор формул комбинаторики\n";
    selecter = InputValidIntRange(1, 2);

    switch (selecter)
    {
    case 1: MatrCalculator(); break;
    // case 2: CombinationCalculator(); break;
    }
    
    return 0;
}