#pragma once
#include "MatrTools.h"
#include <iostream>
#include "ArrayTools.h"
#include "iotools.h"
#include <iomanip>
using namespace std;



sizeofMatrix MatrixInputSize()
{
    cout << "Введите размеры матрицы: ";
    int a[2] = {0, 0}; // массив для структуры размеров...
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
    double** arr = ArrCreate2D_double(size.rows, size.cols);

    ArrFillKeyboard2D_double(arr, size.rows, size.cols);

    eraseline(size.rows);
    return arr;
}

double MatrOprl(double** arr, int size)
{
    if (size == 1) return arr[0][0];
    if (size == 2) return (arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1]);
    if (size == 3) return (arr[0][0] * arr[1][1] * arr[2][2]) + \
                        (arr[1][0] * arr[2][1] * arr[0][2]) + \
                        (arr[0][1] * arr[1][2] * arr[2][0]) \
                                     - \
                        (arr[2][0] * arr[1][1] * arr[0][2]) - \
                        (arr[0][1] * arr[1][0] * arr[2][2]) - \
                        (arr[0][0] * arr[1][2] * arr[2][1]);

    int opr = 0;
    int e;
    for (int k = 0; k < size; k++) // все элементы первой строки (j-й индекс)
    {
        if (k % 2 == 0) e = 1;
        else e = -1;

        double** rez = MatrMinor(arr, size, 0, k);

        opr += e * arr[0][k] * MatrOprl(rez, size-1);

        ArrDelete2D_double(rez, size-1);
    }

    return opr;
}

double** MatrTransp(double** arr, sizeofMatrix size)
{
    sizeofMatrix size1 = { size.cols, size.rows };

    double** neww = ArrCreate2D_double(size1.rows, size1.cols);

    for (int i = 0; i < size.rows; i++)
    {
        for (int j = 0; j < size.cols; j++)
        {
            neww[j][i] = arr[i][j];
        }
    }

    return neww;
}

double** MatrMinor(double **arr, int size, int ind1, int ind2)
{
    double** rz = ArrCreate2D_double(size - 1, size - 1);

    int i1 = 0, j1 = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != ind1 && j != ind2)
            {
                rz[i1][j1] = arr[i][j];

                j1 = j1 + 1;
                if (j1 == (size - 1)) // если j вывалилась за ширину новой матрицы то переходим на новую строку
                {
                    j1 = 0;
                    i1 += 1;
                }
            }
        }
    }

    return rz;
}

void MatrActionWithNum(double** arr, sizeofMatrix size, int act, double num)
{
    switch (act)
    {
    case 1:
    {
        for (int i = 0; i < size.rows; i++)
        {
            for (int j = 0; j < size.cols; j++)
            {
                arr[i][j] = arr[i][j] + num;
            }
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < size.rows; i++)
        {
            for (int j = 0; j < size.cols; j++)
            {
                arr[i][j] = arr[i][j] - num;
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < size.rows; i++)
        {
            for (int j = 0; j < size.cols; j++)
            {
                arr[i][j] = arr[i][j] * num;
            }
        }
        break;
    }
    default: { cout << "ОШИБКА С MatrActionWithNum! \nВыбрана неизвестная операция"; break; }
    }
}

double** MatrActionWithMatr(double** arr, sizeofMatrix size, int act, double** arr1, sizeofMatrix size1)
{
    switch (act)
    {
    case 1: 
    {
        double** rez = ArrCreate2D_double(size.rows, size.cols);
        for (int i = 0; i < size.rows; i++)
        {
            for (int j = 0; j < size.cols; j++)
            {
                rez[i][j] = arr[i][j] + arr1[i][j];
            }
        }
        return rez;
    } break;
    case 2: 
    {
        double** rez = ArrCreate2D_double(size.rows, size.cols);
        for (int i = 0; i < size.rows; i++)
        {
            for (int j = 0; j < size.cols; j++)
            {
                rez[i][j] = arr[i][j] - arr1[i][j];
            }
        }
        return rez;
    } break;
    case 3:
    {
        sizeofMatrix size2 = { size.rows, size1.cols };
        double** rez = ArrCreate2D_double(size2.rows, size2.cols);
        for (int i = 0; i < size.rows; i++)
        {
            for (int j = 0; j < size1.cols; j++)
            {
                double sum = 0;
                for (int k = 0; k < size.cols; k++)
                {
                    sum += arr[i][k] * arr1[k][j];
                }
                rez[i][j] = sum;
            }
        }
        return rez;
    } break;
    default: { cout << "ОШИБКА С MatrActionWithMatr! \nВыбрана неизвестная операция"; break; }
    }
}

void MatrCenterOutput(string cont, int cols, int ed)
{
    cout << setw(cols * SETW + ed) << cont << "\n\n";
}


