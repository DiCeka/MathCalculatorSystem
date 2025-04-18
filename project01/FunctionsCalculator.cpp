#pragma once
#include "Calculators.h"
#include <iostream>
#include "iotools.h"
#include <string>
#include "SDL.h"

using namespace std;
const int vars_amount = 5;
const float APROXIMATY = 0.00001;
const int MAX_ROOTS = 100;
const float STEP = 0.01;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int parameters[vars_amount] = { 0 };
float POLYNOMUS_FUNC(float x) {
	return NULL;
}
float POW_FUNC(float x) {
	return parameters[0] * pow(x, parameters[1]) + parameters[2];
}
float EXP_FUNC(float x) {
	return parameters[0] * pow(parameters[1], parameters[2] * x) +
		parameters[3];
}
float LOG_FUNC(float x) {
	return parameters[0] * log(parameters[1] * x) + parameters[2];
}
float SIN_FUNC(float x) {
	return (parameters[0] * 1.0) * sin(parameters[1] * x * 1.0 + parameters[2]);
}
float COS_FUNC(float x) {
	return (parameters[0] * 1.0) * cos(parameters[1] * x * 1.0 + parameters[2]);
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

SDL_Window *WINDOW;
SDL_Renderer *RENDER;
SDL_Event EVENT;

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

float RootEvaluate(float (*F)(float), float x1, float x2) {
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

int AllRootsResearch(float (*f)(float), float start, float end, float step, float *roots, int maxRoots) {
	float x1 = start;
	float x2 = start + step;
	int count = 0;

	while (x2 <= end && count < maxRoots) {
		if (f(x1) * f(x2) <= 0) {
			float root = RootEvaluate(f, x1, x2);
			roots[count++] = root;
		}
		x1 = x2;
		x2 += step;
	}


	return count;
}

void PROCEDURE_RootEvauluation() {

}

void FunctionsCalculator(bool& isexecuting)
{
	//ВЫБОР ФУНКЦИИ
	string polynomial_title = "1) (В РАЗРАБОТКЕ!!!) Полином степени N (a, N - пользовательские значения)\na0 + a1*x + a2*x^2 + .... + aN*x^N;\n\n";
	string power_title = "2) Степенная функция (a, b, c - пользовательские значения)\na * x^b + c;\n\n";
	string exponental_title = "3) Показательная функция (a, b, c, d - пользовательские значения)\na * b^(c*x)+d;\n\n";
	string logariphmic_title = "4) Логарифмическая функция (a, b, c - пользовательские значения)\na * Ln(b*x) + c\n\n";
	string sin_title = "5) Синусоида (a, b, c, d - пользовательские значения)\na*sin(b*x + c) + d;\n\n";
	string cos_title = "6) Косинусоида (a, b, c, d - пользовательские значения)\na*cos(b*x + c) + d;\n\n\n\n";

	int vars_containing_data[6][vars_amount] = {
		{1,0,0,0,1},
		{1,1,1,0,0},
		{1,1,1,1,0},
		{1,1,1,0,0},
		{1,1,1,1,0},
		{1,1,1,1,0}
	};

	//FUNCTIONS funcs;
	//a b c d N

	string TITLES[6] = { polynomial_title, power_title, exponental_title, 
		logariphmic_title, sin_title, cos_title };

	system("cls");
	cout << "КАЛЬКУЛЯТОР ФУНКЦИЙ\n\n";
	cout << "Перечень допустимых функций: \n\n";

	for (int i = 0; i < 6; i++) cout << TITLES[i];

	int selection_func = iotools_Int_InputInOutRange("Введите номер нужной функции (1-6): ", "Ошибка!", 1, 6, 3);

	system("cls"); cout << "ВЫБРАНА ФУНКЦИЯ: \n\n" << TITLES[selection_func - 1];
	system("pause");

	//ВЫБОР ОПЕРАЦИИ
	string defined_integral_operation_title = "1)(В РАЗРАБОТКЕ!!!) Вычислить определённый интеграл на отрезке [A; B] (пользовательский ввод);\n\n";
	string graph_generation_operation_title = "2) Построение и визуализация графика;\n\n";
	string root_determination_operation_title = "3) Поиск корня (y = 0) на отрезке [A; B] (пользовательский ввод);\n\n";
	string extremes_determination_operation_title = "4)(В РАЗРАБОТКЕ!!!) Поиск экстремумов на отрезке [A; B] (пользовательский ввод);\n\n";

	string OPERATIONS[4] = { defined_integral_operation_title, graph_generation_operation_title, 
		root_determination_operation_title, extremes_determination_operation_title};

	system("cls"); cout << "ПЕРЕЧЕНЬ ВОЗМОЖНЫХ ОПЕРАЦИЙ: \n\n";
	for (int i = 0; i < 4; i++) cout << OPERATIONS[i];

	int selection_operation = iotools_Int_InputInOutRange("\nВыберите нужную операцию (1-4): ", "Ошибка!", 1, 4, 4);

	system("cls");
	cout << "ВЫБРАНА ОПЕРАЦИЯ: \n\n" << OPERATIONS[selection_operation - 1] << "\n\n";
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
	

	for (int i = 0; i < vars_amount; i++) {
		if (vars_containing_data[selection_func - 1][i] == 1) {
			switch (i)
			{
			case 0: cout << "Введите a: "; break;
			case 1: cout << "Введите b: "; break;
			case 2: cout << "Введите c: "; break;
			case 3: cout << "Введите d: "; break;
			case 4: cout << "Введите N: "; break;
			}
			cin >> parameters[i];
		}

	}
	
	float ROOTS[MAX_ROOTS] = {0.0};
	int count_roots = 0;
	
	float(*funcPTRS[])(float) = {&POLYNOMUS_FUNC,&POW_FUNC, &EXP_FUNC, &LOG_FUNC, &SIN_FUNC, &COS_FUNC};
	switch (selection_operation) {
	case 1: //интеграл
		cout << "В РАЗРАБОТКЕ!" << endl;
		break;
	case 2: // график
		GRAPH_VISUALISATOR(funcPTRS[selection_func - 1], interval_begining, interval_ending);
		break;
	case 3: // корни
		count_roots = AllRootsResearch(funcPTRS[selection_func - 1], (float)interval_begining,
			(float)interval_ending, STEP, ROOTS, MAX_ROOTS);

		cout << "Найдено корней: " << count_roots << "\n";
		for (int i = 0; i < count_roots; ++i) {
			cout << ROOTS[i] << "\n";
		}
		cout << endl;
		break;
	case 4: //экстрим
		cout << "В РАЗРАБОТКЕ!" << endl;
		break;

	}
	

	
	//запрос выйти в меню или продолжить этот калькулятор
	CycleRequest(isexecuting);

}

