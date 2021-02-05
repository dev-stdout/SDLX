#include "SDLX.h"

char	*SDLX_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	
	len = SDL_strlen(s1) + SDL_strlen(s2) + 1;
	if (!(str = SDL_malloc(len)))
		return (NULL);

	SDL_strlcpy(str, s1, len);

	SDL_strlcat(str, s2, len);
	return str;
}

void SDLX_RenderMessage(TTF_Font *font, char *msg, const SDL_Rect *src, const SDL_Rect *dst)
{
	SDL_Surface *message;
	SDLX_Display *display;

	display = SDLX_GetDisplay();
	message = TTF_RenderText_Solid(font,
						msg,
						(SDL_Color){255, 255, 255, 255});
	SDL_RenderCopy(display->renderer,
					SDL_CreateTextureFromSurface(display->renderer, message),
					src, dst);
	SDL_FreeSurface(message);
}
