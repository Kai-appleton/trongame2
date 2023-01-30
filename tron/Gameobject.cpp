#include "Gameobject.h"
#include "TextureManager.h"

Gameobject::Gameobject(const char* texturesheet, SDL_Renderer* ren,int x, int y)
{
	renderer = ren;
	objectTexture = TextureManager::LoadTexture(texturesheet, ren);


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
	SDL_RenderCopy(renderer, objectTexture, &srcRect, &destRect);
}