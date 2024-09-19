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
 * @file init_objs.c 
 * @brief <Add Brief Description Here >
 * <Add Extended Description Here>
 * @author Alireza Heidari 
 * @date 08 2022 
 *
 */

#include "common.h"
#include "structs.h"
#include "defs.h"

extern Ball ball;
float BALL_SPEED = 250;

bool coinFlip(void) {
	time_t	t;

	srand((unsigned)time(&t));
	return (rand() % 2 == 1 ? true : false);
}

Ball makeBall(int size) {
	ball.xPosition = WINDOW_WIDTH / 2.0 - size / 2.0;
	ball.yPosition = WINDOW_HEIGHT / 2.0 - size / 2.0;
	ball.xSpeed = BALL_SPEED * (coinFlip() ? 1 : -1);
	ball.ySpeed = BALL_SPEED * (coinFlip() ? 1 : -1);
	ball.size = size;
	return (ball);
}


Player	makePlayer(void) {
	Player player = {
		.yPosition = WINDOW_HEIGHT / 2.0,
	};

	return (player);
}

