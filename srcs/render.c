#include "pac.h"

void draw_map_bg(Master *game)
{
	SDL_Texture *inter = SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIN_SIZE, WIN_SIZE);
	SDL_SetRenderTarget(game->renderer, inter);
	SDL_SetRenderDrawColor(game->renderer,0,0,0,255);
	SDL_RenderClear(game->renderer);
	SDL_SetRenderDrawColor(game->renderer,0,0,255,255);
	int n, i = 0, start;
	while (i < 29)
	{
		printf("Calculating line %d\n",  i);
		n = 0;
		while(n < 28)
		{
			start = n;
			while (game->entities.map[i][n] == 'X')
				n++;
			printf("Start : %d,%d End: %d,%d\n", start * (WIN_SIZE / 27), i * (WIN_SIZE /30), (n) * (WIN_SIZE / 29),  i * (WIN_SIZE /30));
			if (n - start > 2)
				SDL_RenderDrawLine(game->renderer, start * (WIN_SIZE / 27), i * (WIN_SIZE /28), (n - 1) * (WIN_SIZE / 27),  i * (WIN_SIZE /28));
			while (game->entities.map[i][n] != 'X' && n < 28)
				n++;
		}
		i++;
	}
	SDL_SetRenderTarget(game->renderer, NULL);
	game->background = inter;
}
