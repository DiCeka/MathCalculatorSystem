#pragma once
#include <iostream>
#include <string>
using namespace std;
//определение
string polynomial_title;
string power_title;
string exponental_title;
string logariphmic_title;
string sin_title;
string cos_title;
int vars_containing_data[6][VARS_AMOUNT];

string TITLES[6];

int* POLYNOMUS_PARAMS_FILLMENT();
float POLYNOMUS_FUNC(float x);
float POW_FUNC(float x);
float EXP_FUNC(float x);
float LOG_FUNC(float x);
float SIN_FUNC(float x);
float COS_FUNC(float x);

float(*funcPTRS[])(float);