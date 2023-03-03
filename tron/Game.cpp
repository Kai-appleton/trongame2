
#include "Game.h"
#include<iostream>
#include<SDL_image.h>
#include "TextureManager.h"
#include "Gameobject.h"

Gameobject* player;
Gameobject* badsnek;


SDL_Renderer* Game::renderer = nullptr;

/*SDL_Texture* playerTex; //not needed as we now have implemented gameObject to handle all objects
SDL_Rect srcR, destR;*/



Game::Game()
{}


Game::~Game()
{}


void Game::init(const char* title, int x, int y, int window_width, int window_height, bool fullscreen)
{

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystem intialised..." << std::endl;

		window = SDL_CreateWindow(title, x, y, window_width, window_height, flags);
		if (window)
		{
			std::cout << "window created" << std::endl;

		}
		renderer = SDL_CreateRenderer(window, 0,0);
		if (window)
		
		{
			int grid_cell_size = 32; //36
			int grid_width = 2; //29
			int grid_height = 2; //23

			// + 1 so that the last grid lines fit in the screen.
			int window_width = (grid_width * grid_cell_size) + 1;
			int window_height = (grid_height * grid_cell_size) + 1;

			SDL_Color grid_background = { 22, 22, 22, 255 }; //  Barely Black
			SDL_Color grid_line_color = { 255, 255, 255, 255 }; // 44, 44, 44, 255 Dark grey
			SDL_Color grid_cursor_ghost_color = { 44, 44, 44, 255 };
			SDL_Color grid_cursor_color = { 255, 255, 255, 255 }; // White
			// Draw grid background.
			SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
				grid_background.b, grid_background.a);
			std::cout << "background drawn" << std::endl;
			//SDL_RenderClear(renderer);

			// Draw grid lines.
			SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
				grid_line_color.b, grid_line_color.a);
			

			for (int x = 0; x < 1 + grid_width * grid_cell_size;
				x += grid_cell_size) {
				SDL_RenderDrawLine(renderer, x, 0, x, window_height);
				

			}
			

			for (int y = 0; y < 1 + grid_height * grid_cell_size;
				y += grid_cell_size) {
				SDL_RenderDrawLine(renderer, 0, y, window_width, y);
			}
			

		}


		


		/*window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "window created" << std::endl;

		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created" << std::endl;
		}*/

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	player = new Gameobject("assets/player.png",0,0);
	badsnek = new Gameobject("assets/badsnek.png", 50, 50);
	




	//playerTex = TextureManager::LoadTexture("assets/tronyellow.png", renderer);



}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;


	default:
		break;
	}

}

void Game::update()
{

	player->Update();
	badsnek->Update();
	/*cnt++;
	destR.h = 32; //change size of player
	destR.w = 32;

	destR.x = cnt; //player location


	std::cout << cnt << std::endl;*/


}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render();
	badsnek->Render();
	//add stuff to render
	SDL_RenderPresent(renderer);



	

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;

}


