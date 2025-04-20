#pragma once
#include "SDL.h"

#define VARS_AMOUNT 5
#define MAX_ROOTS 1000
extern const float APROXIMATY;

extern const float STEP;
extern const int INTEGRATION_APPROXIMATY;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int* params_a;

extern int parameters[VARS_AMOUNT];


extern bool firstlaunch = true;

extern SDL_Window* WINDOW;
extern SDL_Renderer* RENDER;
extern SDL_Event EVENT;
