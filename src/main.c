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
 * @file main.c
 * @brief main function and game loop
 * <Add Extended Description Here>
 * @author Alireza Heidari
 * @date 08 2024
 *
 */

/* includes */
#include "common.h"
#include "init.h"
#include "init_objs.h"
#include "input.h"
#include "draw.h"


/** global variables */
App app;
Ball ball;
Player player1;
Player player2;

float frameElapsedSecond;
bool served = false;
const float	PLAYER_SPEED = 300.0f;

/* main and the game loop */
int main() {
	Uint32 lastTickMiliSecond;
	Uint32 currTickMiliSesond;
	Uint32 diffMiliSecond;

	// initialize SDL library
	initSDL();

	// exit if error during init SDL. 
	(void)atexit(cleanup);

	// initialize the ball and players
	ball = makeBall(BALL_SIZE);
	player1 = makePlayer();
	player2 = makePlayer();

	lastTickMiliSecond = SDL_GetTicks();

	while (true) {
		doInput();

		currTickMiliSesond = SDL_GetTicks();
		diffMiliSecond = currTickMiliSesond - lastTickMiliSecond;
		frameElapsedSecond = (float)diffMiliSecond / 1000.0f;

		update(frameElapsedSecond);
		lastTickMiliSecond = currTickMiliSesond;
	}

	return 0;
}
