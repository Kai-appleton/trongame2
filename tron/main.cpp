#include"SDL.h"
#include"Game.h"
#include <iostream>

Game* game = nullptr;

int main(int argc, char* argv[])
{

	const int FPS = 60;//cappin frame rate
	const int frameDelay = 1000 / FPS; //max time between frames


	Uint32 frameStart;
	int frameTime;




	game = new Game();

	game->init("snekgame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{

		frameStart = SDL_GetTicks();//how many milliseconds since sdl has been init
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);

		}

	}

	game->clean();





	//creating window
	/*SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);


	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);


	SDL_RenderClear(renderer);


	SDL_RenderPresent(renderer);


	SDL_Delay(3000);*/






	return 0;
}