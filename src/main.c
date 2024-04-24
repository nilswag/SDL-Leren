#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
	SDL_Window* window = (void*)0;
	SDL_Renderer* renderer = (void*)0;
	
	SDL_Init(SDL_INIT_VIDEO);

	int width, height;
	{
		SDL_DisplayMode dm;
		SDL_GetCurrentDisplayMode(0, &dm);
		width = (int) (dm.w / 2);
		height = (int) (dm.h / 2);
	}

	SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

	int running = 1;
	SDL_Event event;
	while(running) {
		while(SDL_PollEvent(&event) != 0) {
			if(event.type == SDL_QUIT)
				running = 0;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderDrawPoint(renderer, width / 2, height / 2);

		SDL_RenderPresent(renderer);
	}


	return 0;
}
