#include "iotools.h"
#include "MatrCalculator.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    cout << "TESTTAST\n";
    setlocale(LC_ALL, "ru");
    // переменная, предназначенная для выбора пользователем нужного калькулятора
    int selecter = iotools_Int_InputInRange("Какой калькулятор хотите использовать?\n\t 1 - Матричный калькулятор\n\t 2 - Калькулятор формул комбинаторики\n",
        "ERROR: Такого калькулятора нет!", 1, 2, 6);
    
    switch (selecter)
    {
    case 1: MatrCalculator(); break;
        // case 2: CombinationCalculator(); break;
    }

    return 0;
}