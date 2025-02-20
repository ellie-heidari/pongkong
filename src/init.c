/* 
 * This file is part of pongkong. 
 * 
 * pongkong is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * pongkong is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with pongkong.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file init.c 
 * @brief <Add Brief Description Here >
 * <Add Extended Description Here>
 * @author Alireza Heidari 
 * @date 08 2022 
 *
 */

/* includes */

#include "common.h"
#include "init.h"

/* defines */

/* variables */
extern App app;

/* Implementation File Code */

void initSDL(void) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL_INIT_VIDEO failed: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("pongkong", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (!app.window) {
		fprintf(stderr, "window failed: %s\n", SDL_GetError());
		exit(1);
	}

	/*We must call SDL_CreatRenderer in order for the draw calls to affect this window. */
	app.renderer = SDL_CreateRenderer(app.window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!app.renderer) {
		fprintf(stderr, "renderer failed: %s\n", SDL_GetError());
		exit(1);
	}
}


void	cleanup(void) {
	if (app.renderer) {
		SDL_DestroyRenderer(app.renderer);
	}

	if (app.window) {
		SDL_DestroyWindow(app.window);
	}

	SDL_Quit();
}
