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
 * @file draw.h
 * @brief contains declarations of functions related to rendering and updating 
 * @author Alireza Heidari
 * @date 08 2022
 */


#ifndef __DRAW_H__
#define __DRAW_H__

#include "common.h"

void update(float elapsedTime);
void updateBall(Ball *ball, float elapsedTime);
void updatePlayers(float elapsedTime);
void updateScore(int player, int points);
void renderBall(Ball *ball);
void renderPlayers(void); 

#endif /* __DRAW_H__ */
