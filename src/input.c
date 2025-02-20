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
 * @file input.c
 * @brief 
 * <Add Extended Description Here>
 * @author Alireza Heidari
 * @date 08 2024
 *
 */

#include "input.h"
#include "common.h"

void doInput(void) {
	SDL_Event	event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;
			default:
				break;
		}
	}
}

