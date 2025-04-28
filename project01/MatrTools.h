#pragma once
#include <string>

struct sizeofMatrix
{
    int rows;
    int cols;
};

const int SETW = 4;

sizeofMatrix MatrixInputSize();

double** MatrixInput(sizeofMatrix size);

double MatrOprl(double** arr, int size);

double** MatrTransp(double** arr, sizeofMatrix size);

//возвращает минор матрицы arr порядка size по элементу с индексами ind1 и ind2
double** MatrMinor(double** arr, int size, int ind1, int ind2);
// в аргумент act передаётся действие которое нужно сделать: 
// 1 - "+"
// 2 - "-"
// 3 - "*"
void MatrActionWithNum(double** arr, sizeofMatrix size, int act, double num);

// в аргумент act передаётся действие которое нужно сделать:
// 1 - "+"
// 2 - "-"
// 3 - "*"
double** MatrActionWithMatr(double** arr, sizeofMatrix size, int act, double** arr1, sizeofMatrix size1);

void MatrCenterOutput(std::string cont, int size, int ed);
