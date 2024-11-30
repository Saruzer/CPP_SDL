#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[])
{
	int w = 640; // window width
	int h = 480; // window height

	int rs = 10; //Render scale(x,y) size
	
	int x = w / (rs * 2); // pixel x pos
	int y = h / (rs * 2); // pixel y pos

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;	
	SDL_Event e;
	bool running = true;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, rs, rs);
	while (running) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EventType::SDL_QUIT) {
				running = false;
			}
			else if (e.type == SDL_EventType::SDL_MOUSEMOTION) {
				x = e.motion.x;
				y = e.motion.y;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawPoint(renderer, x / rs, y / rs);
		SDL_RenderPresent(renderer);

		SDL_Delay(10);
	}
	return 1;
}
