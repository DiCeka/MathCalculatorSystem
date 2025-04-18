#pragma once
#include "Matrix.h"
#include "ArrayTools.h"
#include "iotools.h"
#include <iostream>
using namespace std;

struct sizeofMatrix
{
	int cols;
	int rows;
};

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
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Неверный ввод." << "\n";
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

void MatrixSum(bool &is_executing)
{
	setlocale(LC_ALL, "ru");

	cout << "Сложение матриц\n\n";

    sizeofMatrix size = MatrixInputSize();


	eraseline(3);
	cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";

	double **arr = ArrCreate2D_double(size.rows, size.cols);

	ArrFillKeyboard2D_double(arr, size.rows, size.cols);

    eraseline(3);

	ArrOutput2D_double(arr, size.rows, size.cols);


	

	CycleRequest(is_executing);
}
