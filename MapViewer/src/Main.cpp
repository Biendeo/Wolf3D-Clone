#include <iostream>
#include <SDL.h>

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *window = nullptr;
	window = SDL_CreateWindow("Map Viewer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, NULL);

	if (window == nullptr) {
		std::cerr << "SDL couldn't create a window.\n";
		return 1;
	}

	SDL_Surface *surface = nullptr;
	surface = SDL_GetWindowSurface(window);

	if (surface == nullptr) {
		std::cerr << "SDL couldn't find the surface.\n";
		return 1;
	}

	while (true) {
		static int colour = 0;

		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, colour * 2 % 256, colour * 3 % 256, colour * 5 % 256));

		SDL_UpdateWindowSurface(window);

		++colour;
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}