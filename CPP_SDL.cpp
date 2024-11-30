#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[])
{
	int w = 640; // window width
	int h = 480; // window height

	int rs = 4; //Render scale(x,y) size
	
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;	

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer);
	SDL_RenderSetScale(renderer,rs,rs);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(renderer, w / (rs * 2), h / (rs * 2));
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);
	return 1;
}
