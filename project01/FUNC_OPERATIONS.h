#pragma once
#include <string>

using namespace std;

//¬€¡Œ– Œœ≈–¿÷»»
extern string defined_integral_operation_title;
extern string graph_generation_operation_title;
extern string root_determination_operation_title;
extern string extremes_determination_operation_title;

extern string OPERATIONS[4];


void FUNC_EXTREMES_DEFINITIVE(float f(float), float a, float b);
float FUNC_INTEGRATE_CALCULATIOn(float (*func)(float), float a, float b, int n);
float FUNC_GET_ROOT(float (*F)(float), float x1, float x2);
int FUNC_PROCEDURAL_ROOTS_EVALUATION(float (*f)(float), float start, float end, float step, float* roots, int maxRoots);
