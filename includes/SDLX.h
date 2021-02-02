#ifndef SDLX_H
#define SDLX_H

# include "SDL2/SDL.h"
# include "SDL2/SDL_ttf.h"

# include "SDLX_const.h"
# include "SDLX_config.h"
# include "SDLX_structs.h"


void			SDLX_start(SDLX_Display *dest);

SDLX_Display	*SDLX_GetDisplay(void);

void			SDLX_screen_reset(SDL_Renderer *renderer, SDL_Color *bg_color);

void			SDLX_close(void);

#endif