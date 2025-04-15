#include "iotools.h"
#include "Calculators.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    // переменная, предназначенная для выбора пользователем нужного калькулятора
    int selecter = iotools_Int_InputInOutRange("Какой калькулятор хотите использовать?\n\t 1 - Матричный калькулятор\n\t \
2 - Калькулятор формул комбинаторики\n\t 3 - Калькулятор многочленов\n\t 4 - Калькулятор теории вероятности и мат. статистики\n\t \
5 - Калькулятор обыкновенных дробей\n\t 6 - Работа с функциями\n",
        "ERROR: Такого калькулятора нет!", 1, 6, 10);
    

    switch (selecter)
    {
    case 1: MatrCalculator(); break;
    case 2: CombinationCalculator(); break;
    case 3: PolynimialCalculator(); break;
    case 4: StatisticsCalculator(); break;
    case 5: FractionCalculator(); break;
    case 6: FunctionsCalculator(); break;
    }

    return 0;
}