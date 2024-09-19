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
 * @file draw.c 
 * @brief <Add Brief Description Here >
 * <Add Extended Description Here>
 * @author Alireza Heidari 
 * @date 08 2022 
 *
 */

#include "draw.h"

extern App app;
extern Ball ball;
extern bool served;
extern Player player1;
extern Player player2;
extern const float	PLAYER_SPEED;

void update(float elapsedTime) {
	SDL_SetRenderDrawColor(app.renderer, BACKGROUND_RED, BACKGROUND_GREEN,
			BACKGROUND_BLUE, BACKGROUND_ALPHA);
	SDL_RenderClear(app.renderer);
	updateBall(&ball, elapsedTime);
	updatePlayers(elapsedTime);

	renderBall(&ball);
	renderPlayers();

	// present the drawn frame in the backbuffer to the front buffer(user screen)
	SDL_RenderPresent(app.renderer);
}

void updateBall(Ball *ball, float elapsedTime) {
	// space starts the game
	if (!served) {
		ball->xPosition = WINDOW_WIDTH / 2.0;
		/** TODO: randomize the start y position of ball */
		ball->yPosition = WINDOW_HEIGHT / 2.0;
	}

	ball->xPosition += ball->xSpeed * elapsedTime;
	ball->yPosition += ball->ySpeed * elapsedTime;

	/** left wall collisions */
	if (ball->xPosition < 0) {
		updateScore(2, 1);
		/** ball->xSpeed = fabs(ball->xSpeed); */
	}

	/** right wall collisions */
	if (ball->xPosition > WINDOW_WIDTH - BALL_SIZE) {
		updateScore(1, 1);
		/** ball->xSpeed = -fabs(ball->xSpeed); */
	}

	/** top wall collision */
	if (ball->yPosition < 0) {
		ball->ySpeed = fabs(ball->ySpeed);
	}

	/** bottom wall collision */
	if (ball->yPosition > WINDOW_HEIGHT - BALL_SIZE) {
		ball->ySpeed = -fabs(ball->ySpeed);
	}

}

void updatePlayers(float elapsedTime) {
	const Uint8	*keyboardstate;

	/** player movements */
	keyboardstate = SDL_GetKeyboardState(NULL);

	if (keyboardstate[SDL_SCANCODE_SPACE]) {
		served = true;
	}

	/** player 1 goes up */
	if (keyboardstate[SDL_SCANCODE_W] &&
			player1.yPosition > PLAYER_HEIGHT / 2.0) {

		player1.yPosition -= PLAYER_SPEED * elapsedTime;
	}

	/** player 1 goes down */
	if (keyboardstate[SDL_SCANCODE_S] &&
			player1.yPosition < WINDOW_HEIGHT - PLAYER_HEIGHT / 2.0) {

		player1.yPosition += PLAYER_SPEED * elapsedTime;
	}

	/** player 2 goes up */
	if (keyboardstate[SDL_SCANCODE_U] &&
			player2.yPosition > PLAYER_HEIGHT / 2.0) {

		player2.yPosition -= PLAYER_SPEED * elapsedTime;
	}

	/** player 2 goes down */
	if (keyboardstate[SDL_SCANCODE_J] &&
			player2.yPosition < WINDOW_HEIGHT - PLAYER_HEIGHT / 2.0) {

		player2.yPosition += PLAYER_SPEED * elapsedTime;
	}

	/** ball-player collisions */
	SDL_Rect ballRect = {
		.x = ball.xPosition,
		.y = ball.yPosition,
		.w = ball.size,
		.h = ball.size};
	SDL_Rect p1rect = {
		.x = PLAYER_MARGIN,
		.y = (int)(player1.yPosition) - PLAYER_HEIGHT / 2,
		.w = PLAYER_WIDTH,
		.h = PLAYER_HEIGHT};
	if (SDL_HasIntersection(&ballRect, &p1rect)) {
		ball.xSpeed = fabs(ball.xSpeed);
	}

	SDL_Rect p2rect = {
		.x = WINDOW_WIDTH - PLAYER_MARGIN - PLAYER_WIDTH,
		.y = (int)(player2.yPosition) - PLAYER_HEIGHT / 2,
		.w = PLAYER_WIDTH,
		.h = PLAYER_HEIGHT};

	if (SDL_HasIntersection(&ballRect, &p2rect)) {
		ball.xSpeed = -fabs(ball.xSpeed);
	}
}

void updateScore(int player, int points) {
	char	*fmt = NULL;
	int		len = 36;
	char	buf[len + 1];

	served = false;

	if (player == 1) {
		player1.score += points;
	}

	if (player == 2) {
		player2.score += points;
	}

	fmt = "Player 1: %d | Player 2: %d";
	len = snprintf(NULL, 0, fmt, player1.score, player2.score);
	snprintf(buf, len + 1, fmt, player1.score, player2.score);
	SDL_SetWindowTitle(app.window, buf);
}

void renderBall(Ball *ball) {
	int	size;

	size = ball->size;
	SDL_SetRenderDrawColor(app.renderer, BALL_RED, BALL_GREEN, BALL_BLUE, BALL_ALPHA);
	SDL_Rect rect = {
		.x = ball->xPosition,
		.y = ball->yPosition,
		.w = size,
		.h = size};
	SDL_RenderFillRect(app.renderer, &rect);
	SDL_RenderDrawRect(app.renderer, &rect);
}

void renderPlayers(void) {
	/** render player 1 left */
	SDL_SetRenderDrawColor(app.renderer, PLAYER_RED, PLAYER_GREEN, PLAYER_BLUE,
			PLAYER_ALPHA);

	SDL_Rect p1rect = {
		.x = PLAYER_MARGIN,
		.y = (int)(player1.yPosition) - PLAYER_HEIGHT / 2,
		.w = PLAYER_WIDTH,
		.h = PLAYER_HEIGHT};

	SDL_RenderFillRect(app.renderer, &p1rect);
	SDL_RenderDrawRect(app.renderer, &p1rect);

	/** render player 2 right */
	SDL_SetRenderDrawColor(app.renderer, PLAYER_RED, PLAYER_GREEN, PLAYER_BLUE,
			PLAYER_ALPHA);

	SDL_Rect p2rect = {
		.x = WINDOW_WIDTH - PLAYER_MARGIN - PLAYER_WIDTH,
		.y = (int)(player2.yPosition) - PLAYER_HEIGHT / 2,
		.w = PLAYER_WIDTH,
		.h = PLAYER_HEIGHT};

	SDL_RenderFillRect(app.renderer, &p2rect);
	SDL_RenderDrawRect(app.renderer, &p2rect);
}

