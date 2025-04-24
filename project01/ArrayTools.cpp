#include "ArrayTools.h"
#include "iotools.h"
#include <iostream>
#include <iomanip>
using namespace std;






int* ArrCreate1D_int(int size)
{
    int* a = new int[size];
    for (int i = 0; i < size; i++) a[i] = 1;
    return a;
}

int** ArrCreate2D_int(int rows, int cols)
{
    int** a = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        a[i] = new int[cols];
    }

    return a;
}

double** ArrCreate2D_double(int rows, int cols)
{
    double **a = new double* [rows];

    for (int i = 0; i < rows; i++)
    {
        a[i] = new double[cols];
    }

    return a;
}

void ArrOutput1D_int(int* a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << a[i] << " ";
    }
    cout << "\n";
}

void ArrOutput2D_double(double** a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << a[i][j] << " ";
        }
        cout << "\n\n";
    }
}

void ArrOutput2D_int2Args(int** a, int* b, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        cout << " *" << i << ": ";
        for (int j = 1; j < b[i]; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void ArrFillRand1D_int(int* a, int size, int lBorder, int rBorder)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        a[i] = (rand() % (rBorder - lBorder + 1)) + lBorder;
    }
}

void ArrFillRand2D_int(int** a, int rows, int cols, int lBorder, int rBorder)
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a[i][j] = (rand() % (rBorder - lBorder + 1)) + lBorder;
        }
    }
}

void ArrFillKeyboard2D_double(double** a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        cout << "Введите " << i + 1 << "-ю строку(" << cols << " чис(ла)): ";
        cout << "\033[s";
        for (int j = 0; j < cols; j++)
        {
            bool isinvalid;
            do
            {
                isinvalid = false;
                cin >> a[i][j];
                if (cin.fail()) {
                    isinvalid = true;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Неверный ввод." << "\n";
                    system("pause");
                    eraseline(2);
                    cout << "\033[u" << "\33[0K";
                    for (int k = 0; k < j; k++) cout << a[i][k] << " ";
                }
            } while (isinvalid);
        }
    }
}

void ArrAddElement1D(int*& a, int& size, int elem)
{
    int* newarr = new int[size + 1];
    for (int i = 0; i < size; i++) newarr[i] = a[i];
    newarr[size] = elem;
    size++;
    delete[] a;
    a = newarr;
}

void ArrDelete2D_double(double** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;
}

int ArrCheckElemIn(int* a, int size, int elem)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == elem) return 1;
    }
    return 0;
}
