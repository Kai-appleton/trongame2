#pragma once
#define Game_hpp
#include "SDL.h"
#include<iostream>
#include"SDL_image.h"
#include <stdio.h>


class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int window_width, int window_height, bool fullscreen);


	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

	static SDL_Renderer* renderer;

private:
	bool isRunning;
	SDL_Window* window;
	
	int cnt = 0;
	



};


