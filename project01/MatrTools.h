#pragma once

struct sizeofMatrix
{
    int rows;
    int cols;
};

sizeofMatrix MatrixInputSize();

double** MatrixInput(sizeofMatrix size);

double MatrOprl(double** arr, int size);

