#pragma once
#include "Game.h"

class Gameobject {

public:
	Gameobject(const char* texturesheet, int x, int y);
	~Gameobject();

	void Update();
	void Render();

private:

	int xpos;
	int ypos;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
	


};
