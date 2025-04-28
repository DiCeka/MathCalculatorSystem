#pragma once
#include "MatrTools.h"


int* ArrCreate1D_int(int size);

int** ArrCreate2D_int(int rows, int cols);

double** ArrCreate2D_double(int rows, int cols);

void ArrOutput1D_int(int* a, int size);

void ArrOutput2D_double(double** a, int rows, int cols);

void ArrOutput2D_int2Args(int** a, int* b, int rows);

void ArrFillRand1D_int(int* a, int size, int lBorder, int rBorder);

void ArrFillRand2D_int(int** a, int rows, int cols, int lBorder, int rBorder);

void ArrFillKeyboard2D_double(double** a, int rows, int cols);

void ArrAddElement1D(int*& a, int& size, int elem);

void ArrDelete2D_double(double** a, int m);

int ArrCheckElemIn(int* a, int size, int elem);

void ArrCopy2D_double(double** copy, double** orig, sizeofMatrix size);