#pragma once
#include <iostream>
#include <string>
using namespace std;
//определение
extern string power_title;
extern string exponental_title;
extern string logariphmic_title;
extern string sin_title;
extern string cos_title;
int vars_containing_data[6][VARS_AMOUNT] = {
	{0,0,0,0,1},
	{1,1,1,0,0},
	{1,1,1,1,0},
	{1,1,1,0,0},
	{1,1,1,1,0},
	{1,1,1,1,0}
};

extern string TITLES[6];

int* POLYNOMUS_PARAMS_FILLMENT();
float POLYNOMUS_FUNC(float x);
float POW_FUNC(float x);
float EXP_FUNC(float x);
float LOG_FUNC(float x);
float SIN_FUNC(float x);
float COS_FUNC(float x);

float(*funcPTRS[])(float);