#pragma once
#include "FUNC_DATA_MAIN.h"
void SDL_TERMINATION(SDL_Window* win, SDL_Renderer* REND);
SDL_Renderer* GENERATE_RENDER(SDL_Window* window);
int SDL_INITIALIZATION(SDL_Window*& win, int winW, int winH);
void GRAPH_VISUALISATOR(float (*function)(float), int begin, int end);

