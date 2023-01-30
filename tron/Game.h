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

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);


	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
	int cnt = 0;
	SDL_Renderer* renderer;



};


