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



	ArrDelete2D_double(rez, size.rows);
	ArrDelete2D_double(arr1, size.rows);
    ArrDelete2D_double(arr, size.rows);
	CycleRequest(is_executing);
}

void MatrixRaznost(bool& is_executing)
{
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



	ArrDelete2D_double(rez, size.rows);
	ArrDelete2D_double(arr1, size.rows);
	ArrDelete2D_double(arr, size.rows);
	CycleRequest(is_executing);
}

void MatrixProizvedenie(bool &is_executing)
{
	cout << "Произведение матриц\n\n";

	sizeofMatrix size = MatrixInputSize();
	eraseline(1);
	cout << "Размеры первой матрицы: " << size.rows << "x" << size.cols << "\n\n";
	double** arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "*" << endl;

	sizeofMatrix size1;
	size1.rows = size.cols;
	size1.cols = iotools_Int_Input("Введите количество столбцов второй матрицы:\n", "Неверный ввод", 4);
	eraseline(2);
	cout << "Размеры второй матрицы: " << size1.rows << "x" << size1.cols << "\n\n";

	double** arr1 = MatrixInput(size1);

	eraseline(2);

	ArrOutput2D_double(arr1, size1.rows, size1.cols);

	cout << setw(size.cols * 2 + 1) << "=" << endl;

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

	ArrOutput2D_double(rez, size2.rows, size2.cols);

	ArrDelete2D_double(rez, size.rows);
	ArrDelete2D_double(arr, size.rows);
	ArrDelete2D_double(arr1, size1.rows);
	CycleRequest(is_executing);
}
