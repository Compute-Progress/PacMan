#include "pac.h"

void draw_map_bg(Master *game)
{
	SDL_Texture *inter = SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIN_SIZE, WIN_SIZE);
	SDL_SetRenderTarget(game->renderer, inter);
	SDL_SetRenderDrawColor(game->renderer,0,0,0,255);
	SDL_RenderClear(game->renderer);
	SDL_SetRenderDrawColor(game->renderer,0,0,255,255);
	int n, i = 0, start;
	while (i < 31)
	{
		n = 0;
		while(n < 29)
		{
			start = n;
			while (game->entities.map[i][n] == '2' || game->entities.map[i][n] == '1')
				n++;
			if (n - start > 1)
				SDL_RenderDrawLine(game->renderer, (start * (CELL_W)) + ((CELL_W) / 2), i * (CELL_H) + (CELL_H) / 2, (n * (CELL_W)) - (CELL_W) / 2,  i * (CELL_H)  + (CELL_H) / 2 );
			while ((game->entities.map[i][n] != '2' && game->entities.map[i][n] != '1') && n < 29)
				n++;
		}
		i++;
	}
	n = 0;
	while (n < 29)
	{
		i = 0;
		while(i < 31)
		{
			start = i;
			while (game->entities.map[i][n] == '2' || game->entities.map[i][n] == '0')
				i++;
			SDL_RenderDrawLine(game->renderer, (n * (CELL_W)) + (CELL_W) / 2, (start * (CELL_H)) + (CELL_H)/2, (n * (CELL_W)) + (CELL_W) / 2, (i * (CELL_H)) - (CELL_H)/2);
			while ((game->entities.map[i][n] != '2' && game->entities.map[i][n] != '0') && i < 31)
				i++;
		}
		n++;
	}

	SDL_SetRenderTarget(game->renderer, NULL);
	game->background = inter;
}

void draw_items(Master *game)
{
	int i = 0, n;
	SDL_Rect rect, pos;
	rect = game->entities.player.hitbox;


	while (i < 31)
	{
		n = 0;
		while (n < 29)
		{
			if (game->entities.map[i][n] == '.')
			{
				pos.w = CELL_W / 2;
				pos.h = CELL_H / 2;
				pos.x = n  * CELL_W;
				(i > 14) ? (pos.y = i * CELL_H - CELL_H) : (pos.y = i * CELL_H);
				rect.x =  2 * rect.w;
				rect.y = 0;
				SDL_RenderCopy(game->renderer, game->entities.player.texture, &rect, &pos);
			}
			else if (game->entities.map[i][n] == '#')
			{
				pos.w = CELL_W;
				pos.h = CELL_H;
				pos.x = n  * CELL_W;
				(i > 14) ? (pos.y = i * CELL_H - CELL_H) : (pos.y = i * CELL_H);
				rect.x = 3 * rect.w;
				rect.y = 3 * rect.h;
				SDL_RenderCopy(game->renderer, game->entities.player.texture, &rect, &pos);
			}
			n++;
		}
		i++;
	}
}
