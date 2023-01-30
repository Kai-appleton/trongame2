#include "Gameobject.h"
#include "TextureManager.h"

Gameobject::Gameobject(const char* texturesheet, SDL_Renderer* ren) 
{
	renderer = ren;
	objectTexture = TextureManager::LoadTexture(texturesheet, ren);

}


void Gameobject::Update()
{
	xpos = 0;
	ypos = 0;


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