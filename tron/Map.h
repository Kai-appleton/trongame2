#pragma once
#include "Game.h"

class Map
{
public:

	Map();
	~Map();



	void LoadMap();
	void DrawMap();




private:

	SDL_Rect src, dest;
	SDL_Texture* Grid;


	int map[20][25];

};