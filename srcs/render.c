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
		n = 0;
		while(n < 29)
		{
			start = n;
			while (game->entities.map[i][n] == '2' || game->entities.map[i][n] == '1')
				n++;
			if (n - start > 1)
				SDL_RenderDrawLine(game->renderer, (start * (CELL_H)) + ((CELL_H) / 2), i * (CELL_W) + (CELL_W) / 2, (n * (CELL_H)) - (CELL_H) / 2,  i * (CELL_W)  + (CELL_W) / 2 );
			while ((game->entities.map[i][n] != '2' && game->entities.map[i][n] != '1') && n < 29)
				n++;
		}
		i++;
	}
	n = 0;
	while (n < 29)
	{
		i = 0;
		while(i < 30)
		{
			start = i;
			while (game->entities.map[i][n] == '2' || game->entities.map[i][n] == '0')
				i++;
			SDL_RenderDrawLine(game->renderer, (n * (CELL_H)) + (CELL_H) / 2, (start * (CELL_W)) + (CELL_W)/2, (n* (CELL_H)) + (CELL_H) / 2, (i * (CELL_W)) - (CELL_W)/2);
			while ((game->entities.map[i][n] != '2' && game->entities.map[i][n] != '0') && i < 30)
				i++;
		}
		n++;
	}

	SDL_SetRenderTarget(game->renderer, NULL);
	game->background = inter;
}

void draw_items(Master *game)
{
	int i = 0, n, r, inc, incy;
	SDL_Rect rect, pos;
	rect = game->entities.player.hitbox;
	pos = game->entities.player.hitbox;;
	rect.x =  2 * rect.w;
	rect.y = 0;
	r = CELL_H / 5;
	while (i < 30)
	{
		n = 0;
		while (n < 29)
		{
			if (game->entities.map[i][n] == '.')
			{
				pos.x = n  * CELL_W;
				pos.y = i * CELL_H;
				SDL_RenderCopy(game->renderer, game->entities.player.texture, &rect, &pos);
			}
			n++;
		}
		i++;
	}
}
