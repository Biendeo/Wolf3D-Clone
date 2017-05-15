#include <iostream>
#include <array>
#include <string>
#include <SDL.h>

#include "Map.h"

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

#include "Color.h"

std::array<std::array<Color, WINDOW_WIDTH>, WINDOW_HEIGHT> frameBuffer;

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *window = nullptr;
	window = SDL_CreateWindow("Map Viewer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, NULL);

	if (window == nullptr) {
		std::cerr << "SDL couldn't create a window.\n";
		return 1;
	}

	SDL_Renderer *renderer = nullptr;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	if (renderer == nullptr) {
		std::cerr << "SDL couldn't create the renderer.\n";
		return 1;
	}

	SDL_Texture *currentBuffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);


	SDL_SetRenderDrawColor(renderer, 0, 50, 150, 255);

	Map testMap("dat/test.json");

	bool quit = false;

	while (true) {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
				break;
			}
		}

		if (quit) break;


		// Begin a test scene.
		memset(frameBuffer.data(), 0, sizeof(Color) * WINDOW_HEIGHT * WINDOW_WIDTH);

		static int position = 0;

		for (int i = 0; i < WINDOW_HEIGHT / 2; ++i) {
			frameBuffer[i + WINDOW_HEIGHT / 4][position].B(0xBB);
		}

		++position;
		position %= WINDOW_WIDTH;
		// End the test scene.

		SDL_RenderClear(renderer);

		void *pixels;
		int pitch;
		SDL_LockTexture(currentBuffer, NULL, &pixels, &pitch);

		memcpy(pixels, frameBuffer.data(), sizeof(Color) * WINDOW_WIDTH * WINDOW_HEIGHT);

		SDL_UnlockTexture(currentBuffer);

		SDL_RenderCopy(renderer, currentBuffer, NULL, NULL);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(currentBuffer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}