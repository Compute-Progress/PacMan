#include "pac.h"

void draw_map_bg(Master *game)
{
	SDL_Texture *inter = SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIN_SIZE, WIN_SIZE);
	SDL_SetRenderTarget(game->renderer, inter);
	SDL_SetRenderDrawColor(game->renderer,0,0,0,255);
	SDL_RenderClear(game->renderer);
	SDL_SetRenderDrawColor(game->renderer,0,0,255,255);
	int n, i = 0, start;
	while (i < 30)
	{
		printf("Calculating line %d\n",  i);
		n = 0;
		while(n < 30)
		{
			start = n;
			while (game->entities.map[i][n] == 'X')
				n++;
			printf("Start : %d,%d End: %d,%d\n", start * (WIN_SIZE / 28), i * (WIN_SIZE /30), (n) * (WIN_SIZE / 29),  i * (WIN_SIZE /30));
			if (n - start > 2)
				SDL_RenderDrawLine(game->renderer, start * (WIN_SIZE / 28), i * (WIN_SIZE / 29), (n + 1) * (WIN_SIZE / 28),  i * (WIN_SIZE /29));
			while (game->entities.map[i][n] != 'X' && n < 30)
				n++;
		}
		i++;
	}

	i = 0;
	n = 0;
	while (n < 30)
	{
		printf("Calculating line %d\n",  i);
		i = 0;
		while(i < 30)
		{
			start = i;
			while (game->entities.map[i][n] == 'X')
				i++;
			printf("Start : %d,%d End: %d,%d\n", start * (WIN_SIZE / 28), n * (WIN_SIZE /30), (i) * (WIN_SIZE / 29),  n * (WIN_SIZE /30));
			if (i - start > 2)
				SDL_RenderDrawLine(game->renderer, n * (WIN_SIZE / 28), start * (WIN_SIZE / 29), (n) * (WIN_SIZE / 28),  i * (WIN_SIZE /29));
			while (game->entities.map[i][n] != 'X' && i < 30)
				i++;
		}
		n++;
	}
	SDL_SetRenderTarget(game->renderer, NULL);
	game->background = inter;
}
