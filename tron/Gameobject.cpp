#include "Gameobject.h"
#include "TextureManager.h"

Gameobject::Gameobject(const char* texturesheet,int x, int y)
{
	
	objectTexture = TextureManager::LoadTexture(texturesheet);


	xpos = x;
	ypos = y;

}


void Gameobject::Update()
{
	xpos++;
	ypos++;


	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void Gameobject::Render()
{
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}