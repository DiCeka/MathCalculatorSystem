#include "iotools.h"
#include "Calculators.h"
#include <iostream>
#include <string>
using namespace std;

bool ISEXECUTING = false; //выключатель цикличности каждого калькулятора
int main()
{
    
    setlocale(LC_ALL, "ru");
    while (true) { //программа выполняется бесконечно, пока не закроют консоль
        system("cls");
        // переменная, предназначенная для выбора пользователем нужного калькулятора
        int selecter = iotools_Int_InputInOutRange("Какой калькулятор хотите использовать?\n\t 1 - Матричный калькулятор\n\t \
2 - Калькулятор формул комбинаторики\n\t 3 - Калькулятор многочленов\n\t 4 - Калькулятор теории вероятности и мат. статистики\n\t \
5 - Калькулятор обыкновенных дробей\n\t 6 - Работа с функциями\n",
"ERROR: Такого калькулятора нет!", 1, 6, 10);
        ISEXECUTING = true; //включаем цикличность выбранного калькулятора
        system("cls");
        while (ISEXECUTING) { //пока цикличность активна, будем запускать калькуляторы
            switch (selecter)
            {
            case 1: MatrCalculator(ISEXECUTING); break;
            case 2: CombinationCalculator(ISEXECUTING); break;
            case 3: PolynimialCalculator(ISEXECUTING); break;
            case 4: StatisticsCalculator(ISEXECUTING); break;
            case 5: FractionCalculator(ISEXECUTING); break;
            case 6: FunctionsCalculator(ISEXECUTING); break;
            }
        }
    }

    return 0;
}

