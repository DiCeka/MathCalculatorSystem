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

void MatrixProizvWithNumber(bool &is_executing)
{
	cout << "Произведение матрицы на число\n\n";

	sizeofMatrix size = MatrixInputSize();
	eraseline(1);
	cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";
	double** arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "*" << "\n\n";
	int a = iotools_Int_Input("Введите второй множитель:\n", "Неверный ввод", 4);
	eraseline(2);
	cout << setw(size.cols * 2 + 1) << a << "\n\n";

	double** rez = ArrCreate2D_double(size.rows, size.cols);

	ArrCopy2D_double(rez, arr, size);

	MatrActionWithNum(rez, size, 3, a);

	cout << setw(size.cols * 2 + 1) << "=" << endl;

	ArrOutput2D_double(rez, size.rows, size.cols);


	ArrDelete2D_double(rez, size.rows);
	ArrDelete2D_double(arr, size.rows);
	CycleRequest(is_executing);
}

void MatrixSumWithNumber(bool& is_executing)
{
	cout << "Сложение матрицы с числом\n\n";

	sizeofMatrix size = MatrixInputSize();
	eraseline(1);
	cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";
	double** arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "+" << "\n\n";

	int a = iotools_Int_Input("Введите второе слагаемое(число):\n", "Неверный ввод", 4);
	eraseline(2);
	cout << setw(size.cols * 2 + 1) << a << "\n\n";


	double** rez = ArrCreate2D_double(size.rows, size.cols);

	ArrCopy2D_double(rez, arr, size);

	MatrActionWithNum(rez, size, 1, a);

	cout << setw(size.cols * 2 + 1) << "=" << endl;

	ArrOutput2D_double(rez, size.rows, size.cols);


	ArrDelete2D_double(rez, size.rows);
	ArrDelete2D_double(arr, size.rows);
	CycleRequest(is_executing);
}

void MatrixRaznostWithNumber(bool& is_executing)
{
	cout << "Вычитание из матрицы числа\n\n";

	sizeofMatrix size = MatrixInputSize();
	eraseline(1);
	cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";
	double** arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "-" << "\n\n";

	int a = iotools_Int_Input("Введите вычитаемое:\n", "Неверный ввод", 4);
	eraseline(2);
	cout << setw(size.cols * 2 + 1) << a << "\n\n";


	double** rez = ArrCreate2D_double(size.rows, size.cols);

	ArrCopy2D_double(rez, arr, size);

	MatrActionWithNum(rez, size, 2, a);

	cout << setw(size.cols * 2 + 1) << "=" << endl;

	ArrOutput2D_double(rez, size.rows, size.cols);


	ArrDelete2D_double(rez, size.rows);
	ArrDelete2D_double(arr, size.rows);
	CycleRequest(is_executing);
}

void MatrixTransp(bool& is_executing)
{
	cout << "Транспонирование матрицы\n\n";

	sizeofMatrix size = MatrixInputSize();
	eraseline(1);
	cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";
	double** arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "\\/" << "\n\n";

	sizeofMatrix size1 = {size.cols, size.rows};

	double** rez = ArrCreate2D_double(size1.rows, size1.cols);
	
	ArrCopy2D_double(rez, MatrTransp(arr, size), size1);
	
	ArrOutput2D_double(rez, size1.rows, size1.cols);

	ArrDelete2D_double(rez, size1.rows);
	ArrDelete2D_double(arr, size.rows);
	CycleRequest(is_executing);
}

void MatrixReverse(bool& is_executing)
{
	cout << "Нахождение обратной матрицы\n\n";

	int sizeI = iotools_Int_InputInOutRange("Введите порядок(ширину) матрицы: ", "Неверный ввод. Попробуйте снова", 1, INT_MAX, 1);
	sizeofMatrix size = { sizeI, sizeI };
	eraseline(1);
	cout << "Размеры матрицы: " << size.rows << "x" << size.cols << "\n\n";
	double** arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << setw(size.cols * 2 + 1) << "Обратная матрица:" << "\n\n";

	double oprl = MatrOprl(arr, sizeI);
	cout << oprl << "\n\n";

	if (oprl == 0)
	{
		cout << "Определитель данной матрицы равен 0. \n Обратной матрицы не существует.";
	}
	else
	{
		double** rez = ArrCreate2D_double(sizeI, sizeI);

		int r = 1;
		for (int i = 0; i < sizeI; i++)
		{
			for (int j = 0; j < sizeI; j++)
			{
				rez[i][j] = r * MatrOprl(MatrMinor(arr, sizeI, i, j), sizeI - 1);

				r *= -1;
			}
			if (sizeI % 2 == 0) r *= -1;
		}
		double** rez1 = ArrCreate2D_double(sizeI, sizeI);
		// транспонирование
		for (int i = 0; i < size.rows; i++)
		{
			for (int j = 0; j < size.cols; j++)
			{
				rez1[j][i] = rez[i][j];
			}
		}
		MatrActionWithNum(rez1, size, 3, (1.0 / oprl));

		ArrOutput2D_double(rez1, sizeI, sizeI);
		ArrDelete2D_double(rez1, sizeI);
		ArrDelete2D_double(rez, sizeI);
	}


	


	ArrDelete2D_double(arr, sizeI);
	CycleRequest(is_executing);
}

void MatrixOpredelitel(bool& is_executing)
{
	cout << "Нахождение определителя матрицы\n\n";

	int sizeI = iotools_Int_InputInOutRange("Введите порядок(ширину) матрицы: ", "Неверный ввод. Попробуйте снова", 1, INT_MAX, 1);
	sizeofMatrix size = {sizeI, sizeI};
	eraseline(1);
	cout << "Размеры матрицы: " << sizeI << "x" << sizeI << "\n\n";
	double** arr = MatrixInput(size);
	ArrOutput2D_double(arr, size.rows, size.cols);

	cout << "Определитель матрицы равен:" << "\n\n";

	cout << setw(sizeI * 2 + 1) << MatrOprl(arr, size.cols) << "\n\n";
	
	ArrDelete2D_double(arr, size.rows);
	CycleRequest(is_executing);
}