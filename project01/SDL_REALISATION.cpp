#pragma once
#include "SDL_WORK.h"
#include <iostream>
using namespace std;
void SDL_TERMINATION(SDL_Window* win, SDL_Renderer* REND) {
	SDL_DestroyRenderer(REND);
	SDL_DestroyWindow(win); SDL_Quit();

}
SDL_Renderer* GENERATE_RENDER(SDL_Window* window) {
	SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (rend == NULL) { cout << "ERROR: Render generator FAIL! " << SDL_GetError() << endl; return NULL; }
	else cout << "RENDERER: Successful generation\n ";
	return rend;
}
int SDL_INITIALIZATION(SDL_Window*& win, int winW, int winH) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { return 1;  cout << "ERROR! " << SDL_GetError() << endl; }

	win = SDL_CreateWindow(u8"Визуализация", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winW, winH, SDL_WINDOW_SHOWN);
	if (win == NULL) { return 1; cout << "ERROR! " << SDL_GetError() << endl; }
	cout << "Successfull SDL init.\n";
	//scr = SDL_GetWindowSurface(win); 
	return 0;

}
void GRAPH_VISUALISATOR(float (*function)(float), int begin, int end) {
	//system("cls");
	SDL_INITIALIZATION(WINDOW, SCREEN_WIDTH, SCREEN_HEIGHT);
	RENDER = GENERATE_RENDER(WINDOW);
	bool IS_EXECUTE_WINDOW = true;

	int DENSITY = 20;
	int offsetX = 0;
	int offsetY = 0;
	cout << "Управление: " << "\n '1' / '2' увеличить, уменьшить масштаб\n\n\n";
	while (IS_EXECUTE_WINDOW) {
		while (SDL_PollEvent(&EVENT) != 0) {

			switch (EVENT.type)
			{
			case SDL_QUIT:
				IS_EXECUTE_WINDOW = false;
				break;

			}
		}
		

		const Uint8 *keycapture = SDL_GetKeyboardState(NULL);
		if (keycapture[SDL_SCANCODE_1] && DENSITY <= 100) DENSITY += 1;
		if (keycapture[SDL_SCANCODE_2] && DENSITY >= 2) DENSITY -= 1;
		/*
		if (keycapture[SDL_SCANCODE_A] && offsetX >= -SCREEN_WIDTH+1) offsetX += 10;
		if (keycapture[SDL_SCANCODE_D] && offsetX <= SCREEN_WIDTH - 1) offsetX -= 10;
		if (keycapture[SDL_SCANCODE_W] && offsetX >= -SCREEN_HEIGHT + 1) offsetY += 10;
		if (keycapture[SDL_SCANCODE_S] && offsetX <= SCREEN_HEIGHT - 1) offsetY -= 10;
		*/
		SDL_SetRenderDrawColor(RENDER, 255, 255, 255, 255);
		SDL_Rect screen; screen.x = 0; screen.y = 0; screen.w = SCREEN_WIDTH; screen.h = SCREEN_HEIGHT;
		SDL_RenderFillRect(RENDER, &screen);


		SDL_SetRenderDrawColor(RENDER, 240, 240, 240, 255);
		int height_middle = SCREEN_HEIGHT / 2;
		int width_middle = SCREEN_WIDTH / 2;

		for (int x = width_middle + offsetX; x < SCREEN_WIDTH + offsetX; x += DENSITY) {
			SDL_RenderDrawLine(RENDER, x, 0, x, SCREEN_HEIGHT);
		}
		for (int x = width_middle + offsetX; x >= 0 + offsetX; x -= DENSITY) {
			SDL_RenderDrawLine(RENDER, x, 0, x, SCREEN_HEIGHT);
		}
		for (int y = height_middle + offsetX; y < SCREEN_HEIGHT + offsetX; y += DENSITY) {
			SDL_RenderDrawLine(RENDER, 0, y, SCREEN_WIDTH, y);
		}
		for (int y = height_middle + offsetX; y >= 0 + offsetX; y -= DENSITY) {
			SDL_RenderDrawLine(RENDER, 0, y, SCREEN_WIDTH, y);
		}
		int prevX = 0; int prevY = 0;

		for (int Px = -width_middle; Px < width_middle; Px += 1) {
			SDL_SetRenderDrawColor(RENDER, 255, 183, 0, 255);
			float mX = (float)Px / DENSITY;
			float mY = function(mX);

			int pY = (int)(-mY * DENSITY);
			if (mX > begin && mX < end)
				SDL_RenderDrawLine(RENDER, prevX + offsetX, prevY + offsetY, Px + width_middle + offsetX, pY + height_middle + offsetY);

			SDL_SetRenderDrawColor(RENDER, 73, 130, 72, 255);
			if (mX == begin) {
				for (int y = 0; y < SCREEN_HEIGHT; y += DENSITY * 2) {
					SDL_RenderDrawLine(RENDER, Px + width_middle + offsetX, y + offsetY, Px + width_middle + offsetX, y + DENSITY + offsetY);
				}
			}
			if (mX == end) {
				for (int y = 0; y < SCREEN_HEIGHT; y += DENSITY * 2) {
					SDL_RenderDrawLine(RENDER, Px + width_middle + offsetX, y + offsetY, Px + width_middle + offsetX, y + DENSITY + offsetY);
				}
			}
			prevX = Px + width_middle;
			prevY = pY + height_middle;

		}


		SDL_SetRenderDrawColor(RENDER, 0, 0, 0, 255);
		SDL_RenderDrawLine(RENDER, 0 + offsetX, SCREEN_HEIGHT / 2 + offsetY, SCREEN_WIDTH + offsetX, SCREEN_HEIGHT / 2 + offsetY);
		SDL_RenderDrawLine(RENDER, SCREEN_WIDTH / 2 + offsetX, 0 + offsetY, SCREEN_WIDTH / 2 + offsetX, SCREEN_HEIGHT + offsetY);



		SDL_RenderPresent(RENDER);
		SDL_Delay(16);
		//	system("cls");
	}
	SDL_TERMINATION(WINDOW, RENDER);

}

