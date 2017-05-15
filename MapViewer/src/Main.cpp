#include <iostream>
#include <array>
#include <string>
#include <SDL.h>

#include "Map.h"

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

#include "Color.h"
#include "Framebuffer.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *window = nullptr;
	window = SDL_CreateWindow("Map Viewer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

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

	Framebuffer frameBuffer(WINDOW_WIDTH, WINDOW_HEIGHT);
	Map testMap("dat/test.json");

	bool quit = false;

	while (true) {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
				break;
			} else if (event.type == SDL_WINDOWEVENT) {
				switch (event.window.event) {
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						SDL_DestroyTexture(currentBuffer);
						currentBuffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, event.window.data1, event.window.data2);
						frameBuffer.Resize(event.window.data1, event.window.data2);
						break;
				}
			} else {
				std::cout << "BLERGH";
			}
		}

		if (quit) break;


		// Begin a test scene.
		frameBuffer.Flush();

		static int position = 0;
		position %= frameBuffer.Width();

		for (int i = 0; i < frameBuffer.Height() / 2; ++i) {
			frameBuffer.Set(position, i + frameBuffer.Height() / 4, 0x000000BB);
		}

		++position;
		// End the test scene.

		SDL_RenderClear(renderer);

		void *pixels;
		int pitch;
		SDL_LockTexture(currentBuffer, NULL, &pixels, &pitch);

		memcpy(pixels, frameBuffer.Data(), sizeof(Color) * frameBuffer.Width() * frameBuffer.Height());

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