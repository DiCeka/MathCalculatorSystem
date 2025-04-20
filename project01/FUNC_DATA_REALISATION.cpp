#pragma once
#include "FUNC_DATA_MAIN.h"


const float APROXIMATY = 0.00001;

const float STEP = 0.001;
const int INTEGRATION_APPROXIMATY = 150;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int* params_a;

int parameters[VARS_AMOUNT];


bool firstlaunch;

SDL_Window* WINDOW=nullptr;
SDL_Renderer* RENDER=nullptr;
SDL_Event EVENT;
