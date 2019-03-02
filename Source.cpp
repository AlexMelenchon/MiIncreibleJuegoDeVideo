#include "SDL/include/SDL.h"

#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")

int main(int argc, char * argv[]) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	SDL_Window *window;
	SDL_Renderer *renderer = NULL;
	SDL_Event event;


	window = SDL_CreateWindow(
		"Cuadradito <3",                  // window title
		SDL_WINDOWPOS_CENTERED,           // initial x position
		SDL_WINDOWPOS_CENTERED,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	

	SDL_Rect dstrect;

	dstrect.x = 190;
	dstrect.y = 110;
	dstrect.w = 240;
	dstrect.h = 240;
	

	while (true) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &dstrect);
		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case (SDL_KEYDOWN):
				switch (event.key.keysym.sym) {
				case SDLK_LEFT: dstrect.x -= 15; break;
				case SDLK_RIGHT: dstrect.x += 15; break;
				case SDLK_UP: dstrect.y -= 15; break;
				case SDLK_DOWN: dstrect.y += 15; break;
				default: break;
			}
				break;
			default: break;



			}
		}
	}

	return 0;
}