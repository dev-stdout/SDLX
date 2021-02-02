/***************************************************************************
 * FILENAME:    SDLX_render_queue.c
 * DESCRIPTION: General Functions to render.
 *
 * ENVIRONMENT:
 *     macOS Cataline 10.15.7
 *     Visual Studio Code 1.30
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 24Jan2021
***************************************************************************/

#include "SDLX_structs.h"

void	SDLX_draw_animation(SDL_Renderer *renderer, SDLX_Sprite *animation)
{
	size_t	no;

	no = animation->current % animation->sprite->cycle;

	SDL_RenderCopyEx(renderer,
	animation->sprite[no].texture,
	NULL,

	&animation->dst,
	animation->angle,
	animation->center,
	animation->flip);
}

void	SDLX_draw_queue(SDLX_RenderQueue *queue, SDL_Renderer *renderer)
{
	size_t	i;

	i = 0;
	while (i < queue->index)
	{
		SDLX_draw_animation(renderer, queue->content[i]);
		i++;
	}
}

void	SDLX_send_to_render(SDLX_RenderQueue *dst, SDLX_Sprite *src)
{
	if (dst->index + 1 >= dst->capacity)
		SDL_realloc(dst->content, sizeof(dst->content) * (dst->capacity * ALLOC_RATE));

	dst->content[dst->index] = src;
	dst->index += 1;
}
