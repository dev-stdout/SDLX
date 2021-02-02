/***************************************************************************
 * FILENAME:	SDLX_structs.h
 * DESCRIPTION: Structures to be used by SDLX and external files.
 *
 * ENVIRONMENT:
 *	 macOS Cataline 10.15.7
 *	 Visual Studio Code 1.30
 * AUTHORS:
 *	 Kevin Colour
 * DATES:
 *	 Created: 24Jan2021
***************************************************************************/

#ifndef SDLX_structs_H
#define SDLX_structs_H

# include "SDL2/SDL.h"

# include "SDLX_const.h"

typedef struct SDLX_Display
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
}	SDLX_Display;

typedef struct SDLX_Sprite_Data
{
	SDL_Texture		*texture;
	size_t			cycle;
}	SDLX_Sprite_Data;

typedef struct SDLX_Sprite
{
	size_t				current;

	SDLX_Sprite_Data	*sprite;

	SDL_Rect			dst;
	double				angle;
	SDL_Point			*center;
	SDL_RendererFlip	flip;
}	SDLX_Sprite;

typedef struct SDLX_RenderQueue
{
	size_t			index;
	size_t			capacity;

	SDLX_Sprite		**content;
}	SDLX_RenderQueue;


#endif