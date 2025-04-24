#pragma once
#include "MatrTools.h"
#include <iostream>
#include "ArrayTools.h"
#include "iotools.h"
using namespace std;


sizeofMatrix MatrixInputSize()
{
    cout << "Введите размеры матрицы: ";
    int a[2]; // массив для структуры размеров...
    cout << "\033[s";
    for (int i = 0; i < 2; i++)
    {
        bool isinvalid;
        do
        {
            isinvalid = false;
            cin >> a[i];
            if (cin.fail()) {
                isinvalid = true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Неверный ввод.\n";
                system("pause");
                eraseline(2);
                cout << "\033[u" << "\33[0K";
                for (int k = 0; k < i; k++) cout << a[k] << " ";
            }
        } while (isinvalid);
    }
    sizeofMatrix size = { a[0] , a[1] };
    return size;
}

double ** MatrixInput(sizeofMatrix size)
{
    //cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";

    double** arr = ArrCreate2D_double(size.rows, size.cols);

    ArrFillKeyboard2D_double(arr, size.rows, size.cols);

    eraseline(2);
    return arr;
}



