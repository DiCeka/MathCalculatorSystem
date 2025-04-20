#pragma once
#include "Calculators.h"
#include <iostream>
#include "iotools.h"
#include <string>
#include "SDL.h"
#include "FUNC_DATA_MAIN.h"
#include "FUNCTIONS_DEFINITION.h"

using namespace std;





//ВЫБОР ОПЕРАЦИИ
string defined_integral_operation_title = "1) Вычислить определённый интеграл на отрезке [A; B] (пользовательский ввод);\n\n";
string graph_generation_operation_title = "2) Построение и визуализация графика;\n\n";
string root_determination_operation_title = "3) Поиск корня (y = 0) на отрезке [A; B] (пользовательский ввод);\n\n";
string extremes_determination_operation_title = "4)(В РАЗРАБОТКЕ!!!) Поиск экстремумов на отрезке [A; B] (пользовательский ввод);\n\n";

string OPERATIONS[4] = { defined_integral_operation_title, graph_generation_operation_title,
	root_determination_operation_title, extremes_determination_operation_title };


int selection_func;
int selection_operation;

void FUNC_EXTREMES_DEFINITIVE(float f (float), float a, float b) {
	float x1 = a;
	float x2 = x1 + STEP;
	float x3 = x2 + STEP;

	while (x3 <= b) {
		float y1 = f(x1);
		float y2 = f(x2);
		float y3 = f(x3);

		// Проверяем локальный экстремум: если середина выше/ниже соседей
		if ((y2 > y1 && y2 > y3) || (y2 < y1 && y2 < y3)) {
			std::cout << "Экстремум в x = " << x2 << ", f(x) = " << y2;
			if (y2 > y1 && y2 > y3)
				std::cout << " → максимум\n";
			else
				std::cout << " → минимум\n";
		}

		// Двигаем окно
		x1 = x2;
		x2 = x3;
		x3 += STEP;
	}
}



float FUNC_INTEGRATE_CALCULATIOn(float (*func)(float), float a, float b, int n) {
	float h = (b - a) / n;
	float sum = 0.5 * (func(a) + func(b));

	for (int i = 1; i < n; ++i) {
		sum += func(a + i * h);
	}
	return sum * h;
}

void SDL_TERMINATION(SDL_Window* win, SDL_Renderer* REND) {
	SDL_DestroyRenderer(REND);
	SDL_DestroyWindow(win); SDL_Quit();

}
SDL_Renderer* GENERATE_RENDER(SDL_Window* window) {
	SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (rend == NULL) { std::cout << "ERROR: Render generator FAIL! " << SDL_GetError() << std::endl; return NULL; }
	else std::cout << "RENDERER: Successful generation\n ";
	return rend;
}
int SDL_INITIALIZATION(SDL_Window*& win, int winW, int winH) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { return 1;  std::cout << "ERROR! " << SDL_GetError() << std::endl; }

	win = SDL_CreateWindow(u8"Визуализация", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winW, winH, SDL_WINDOW_SHOWN);
	if (win == NULL) { return 1; std::cout << "ERROR! " << SDL_GetError() << std::endl; }
	std::cout << "Successfull SDL init.\n";
	//scr = SDL_GetWindowSurface(win); 
	return 0;

}


void GRAPH_VISUALISATOR(float (*function)(float), int begin, int end) {
	SDL_INITIALIZATION(WINDOW, SCREEN_WIDTH, SCREEN_HEIGHT);
	RENDER = GENERATE_RENDER(WINDOW);
	bool IS_EXECUTE_WINDOW = true;

	int DENSITY = 20;
	while (IS_EXECUTE_WINDOW) {
		while (SDL_PollEvent(&EVENT) != 0) {

			switch (EVENT.type)
			{
			case SDL_QUIT:
				IS_EXECUTE_WINDOW = false;
				break;

			}
		}
		//cout << "Масштаб: " << DENSITY << endl;


		SDL_SetRenderDrawColor(RENDER, 255, 255, 255, 255);
		SDL_Rect screen; screen.x = 0; screen.y = 0; screen.w = SCREEN_WIDTH; screen.h = SCREEN_HEIGHT;
		SDL_RenderFillRect(RENDER, &screen);


		SDL_SetRenderDrawColor(RENDER, 240, 240, 240, 255);
		int height_middle = SCREEN_HEIGHT / 2;
		int width_middle = SCREEN_WIDTH / 2;

		for (int x = width_middle; x < SCREEN_WIDTH; x += DENSITY) {
			SDL_RenderDrawLine(RENDER, x, 0, x, SCREEN_HEIGHT);
		}
		for (int x = width_middle; x >= 0; x -= DENSITY) {
			SDL_RenderDrawLine(RENDER, x, 0, x, SCREEN_HEIGHT);
		}
		for (int y = height_middle; y < SCREEN_HEIGHT; y += DENSITY) {
			SDL_RenderDrawLine(RENDER, 0, y, SCREEN_WIDTH, y);
		}
		for (int y = height_middle; y >= 0; y -= DENSITY) {
			SDL_RenderDrawLine(RENDER, 0, y, SCREEN_WIDTH, y);
		}
		int prevX = 0; int prevY = 0;

		for (int Px = -width_middle; Px < width_middle; Px += 1) {
			SDL_SetRenderDrawColor(RENDER, 255, 183, 0, 255);
			float mX = (float)Px / DENSITY;
			float mY = function(mX);
					
			int pY = (int)(-mY * DENSITY);
			if (mX > begin && mX < end)
				SDL_RenderDrawLine(RENDER, prevX, prevY, Px + width_middle, pY + height_middle);

			SDL_SetRenderDrawColor(RENDER, 73, 130, 72, 255);
			if (mX == begin) {
				for (int y = 0; y < SCREEN_HEIGHT; y += DENSITY * 2) {
					SDL_RenderDrawLine(RENDER, Px + width_middle, y, Px + width_middle, y + DENSITY);
				}
			}
			if (mX == end) {
				for (int y = 0; y < SCREEN_HEIGHT; y += DENSITY * 2) {
					SDL_RenderDrawLine(RENDER, Px + width_middle, y, Px + width_middle, y + DENSITY);
				}
			}
			prevX = Px + width_middle;
			prevY = pY + height_middle;

		}


		SDL_SetRenderDrawColor(RENDER, 0, 0, 0, 255);
		SDL_RenderDrawLine(RENDER, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
		SDL_RenderDrawLine(RENDER, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);



		SDL_RenderPresent(RENDER);
		SDL_Delay(16);
	//	system("cls");
	}
	SDL_TERMINATION(WINDOW, RENDER);

}

float FUNC_GET_ROOT(float (*F)(float), float x1, float x2) {
	float mid;
	while ((x2 - x1) > APROXIMATY) {
		mid = (x1 + x2) / 2.0;
		if (F(x1) * F(mid) <= 0)
			x2 = mid;
		else
			x1 = mid;
	}
	return (x1 + x2) / 2.0;

}

int FUNC_PROCEDURAL_ROOTS_EVALUATION(float (*f)(float), float start, float end, float step, float *roots, int maxRoots) {
	float x1 = start;
	float x2 = start + step;
	int count = 0;

	while (x2 <= end && count < maxRoots) {
		if (f(x1) * f(x2) <= 0) {
			float root = FUNC_GET_ROOT(f, x1, x2);
			roots[count++] = root;
		}
		x1 = x2;
		x2 += step;
	}


	return count;
}



void FunctionsCalculator(bool& isexecuting)
{
	firstlaunch = true;
	
	system("cls");
	cout << "КАЛЬКУЛЯТОР ФУНКЦИЙ\n\n";
	cout << "Перечень допустимых функций: \n\n";

	for (int i = 0; i < 6; i++) cout << TITLES[i];

	selection_func = iotools_Int_InputInOutRange("Введите номер нужной функции (1-6): ", "Ошибка!", 1, 6, 3);

	system("cls"); cout << "ВЫБРАНА ФУНКЦИЯ: \n\n" << TITLES[selection_func - 1].erase(0, 3);
	system("pause");

	system("cls"); cout << "ПЕРЕЧЕНЬ ВОЗМОЖНЫХ ОПЕРАЦИЙ: \n\n";
	for (int i = 0; i < 4; i++) cout << OPERATIONS[i];

	selection_operation = iotools_Int_InputInOutRange("\nВыберите нужную операцию (1-4): ", "Ошибка!", 1, 4, 4);

	system("cls");
	cout << "ВЫБРАНА ОПЕРАЦИЯ: \n\n" << OPERATIONS[selection_operation - 1].erase(0, 3) << "\n\n";
	system("pause");



	//РАБОТА С ВЫБРАННЫМИ ПАРАМЕТРАМИ
	system("cls");
	cout << "С ЧЕМ РАБОТАЕМ?\n\n" << TITLES[selection_func - 1].erase(0,3)<< endl;
	cout << "НАД ЧЕМ РАБОТАЕМ?\n\n" << OPERATIONS[selection_operation - 1].erase(0, 3) << endl;


	///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ХОД ОПЕРАЦИИ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cout << "\n\nХОД ВЫПОЛНЕНИЯ ОПЕРАЦИИ:\n\n";


	//ЗАПОЛНЕНИЕ ДИАПАЗОНА
	cout << "Введите начало диапазона для x: ";
	int interval_begining; cin >> interval_begining;
	int interval_ending = iotools_Int_InputMoreLessThanValue("Введите конец для диапазона x: ", "Конец не может быть таким", interval_begining, 3);

	cout << "Работаем на интервале [" << interval_begining << "; " << interval_ending << "]\n";


	//ЗАПОЛНЕНИ ПАРАМЕТРОВ a,b,c,d,N
	
	
	for (int i = 0; i < VARS_AMOUNT; i++) {
		if (vars_containing_data[selection_func - 1][i] == 1) {
			switch (i)
			{
			case 0: cout << "Введите a: "; break;
			case 1: cout << "Введите b: "; break;
			case 2: cout << "Введите c: "; break;
			case 3: cout << "Введите d: "; break;
			case 4: cout << "Введите N: "; 
				
				break;
			}
			cin >> parameters[i];
			if (i == 4) params_a = POLYNOMUS_PARAMS_FILLMENT();
		}

	}
	
	float ROOTS[MAX_ROOTS] = {0.0};
	int count_roots = 0;
	
	switch (selection_operation) {
	case 1: //интеграл
		cout << "Определённый интеграл от: " << interval_begining << " до " << interval_ending << " равен: " <<
			FUNC_INTEGRATE_CALCULATIOn(funcPTRS[selection_func - 1], interval_begining, interval_ending, INTEGRATION_APPROXIMATY);
		cout << endl;
		break;
	case 2: // график
		GRAPH_VISUALISATOR(funcPTRS[selection_func - 1], interval_begining, interval_ending);
		break;
	case 3: // корни
		count_roots = FUNC_PROCEDURAL_ROOTS_EVALUATION(funcPTRS[selection_func - 1], (float)interval_begining,
			(float)interval_ending, STEP, ROOTS, MAX_ROOTS);

		cout << "Найдено корней: " << count_roots << "\n";
		for (int i = 0; i < count_roots; ++i) {
			cout << ROOTS[i] << "\n";
		}
		cout << endl;
		break;
	case 4: //экстрим
		FUNC_EXTREMES_DEFINITIVE(funcPTRS[selection_func - 1], interval_begining, interval_ending);
		break;

	}
	GRAPH_VISUALISATOR(funcPTRS[selection_func - 1], interval_begining, interval_ending);

	delete[] params_a;
	
	//запрос выйти в меню или продолжить этот калькулятор
	CycleRequest(isexecuting);

}

