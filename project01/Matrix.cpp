#pragma once
#include "Matrix.h"
#include "ArrayTools.h"
#include "iotools.h"
#include <iostream>
#include "MatrTools.h"
#include <iomanip>
using namespace std;



void MatrixSum(bool &is_executing)
{
	setlocale(LC_ALL, "ru");

	cout << "Сложение матриц\n\n";

    sizeofMatrix size = MatrixInputSize();
	eraseline(size.rows);
	cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";
	double **arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << setw(size.cols *2+1) << "+" << endl;

	double** arr1 = MatrixInput(size);
	ArrOutput2D_double(arr1, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "=" << endl;

	double** rez = ArrCreate2D_double(size.rows, size.cols);
	
	for (int i = 0; i < size.rows; i++)
	{
		for (int j = 0; j < size.cols; j++)
		{
			rez[i][j] = arr[i][j] + arr1[i][j];
		}
	}
	ArrOutput2D_double(rez, size.rows, size.cols);



	ArrDelete2D_double(rez, size.cols, size.rows);
	ArrDelete2D_double(arr1, size.cols, size.rows);
    ArrDelete2D_double(arr, size.cols, size.rows);
	CycleRequest(is_executing);
}

void MatrixRaznost(bool& is_executing)
{
	setlocale(LC_ALL, "ru");

	cout << "Вычитание матриц\n\n";

	sizeofMatrix size = MatrixInputSize();
	eraseline(size.rows);
	cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";
	double** arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "-" << endl;

	double** arr1 = MatrixInput(size);
	ArrOutput2D_double(arr1, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "=" << endl;

	double** rez = ArrCreate2D_double(size.rows, size.cols);

	for (int i = 0; i < size.rows; i++)
	{
		for (int j = 0; j < size.cols; j++)
		{
			rez[i][j] = arr[i][j] - arr1[i][j];
		}
	}
	ArrOutput2D_double(rez, size.rows, size.cols);



	ArrDelete2D_double(rez, size.cols, size.rows);
	ArrDelete2D_double(arr1, size.cols, size.rows);
	ArrDelete2D_double(arr, size.cols, size.rows);
	CycleRequest(is_executing);
}
