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
 * @file structs.h
 * @brief all structures used in program are here
 * @author Alireza Heidari
 * @date 08 2022
 */


#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "common.h"

/* Add Declarations and Function Comments here */

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 * all structures defined here.
 * Ball and Player variables are declared in main.c
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window   *window;
} App;



typedef struct Ball {
	float	xPosition;
	float	yPosition;
	float	xSpeed;
	float	ySpeed;
	int		size;
}	Ball;

typedef struct Player {
	int		score;
	float	yPosition;
}	Player;

#endif /* __STRUCTS_H__ */
