
#include "Game.h"
#include<iostream>
#include<SDL_image.h>
#include "TextureManager.h"
#include "Gameobject.h"

Gameobject* player;
Gameobject* badsnek;

/*SDL_Texture* playerTex; //not needed as we now have implemented gameObject to handle all objects
SDL_Rect srcR, destR;*/



Game::Game()
{}


Game::~Game()
{}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystem intialised..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "window created" << std::endl;

		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	player = new Gameobject("assets/player.png", renderer,0,0);
	badsnek = new Gameobject("assets/badsnek.png", renderer, 50, 50);




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


