#include "pac.h"
/*
Ghost *init_ghost(Master *game)
{
	int i = 0;

	game->entities->ghost[0]->parent.coorddinates.position.x = 0;

}
 */

void init_player(Master *game)
{
	int w, h, i = 0, n;
	SDL_Surface *surf;
	SDL_Texture *tex;
	SDL_Texture *inter;
	SDL_Rect rect;

	surf = IMG_Load("imgs/SpriteSheet.png");
	inter = SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIN_SIZE, WIN_SIZE);
	tex = SDL_CreateTextureFromSurface(game->renderer, surf);
	SDL_SetRenderTarget(game->renderer, inter);

	SDL_QueryTexture(tex, NULL, NULL,  &w, &h);
	rect.h = (h / 10) * 4;
	rect.w = w;
	rect.x = 5;
	rect.y = 0;
	SDL_RenderCopy(game->renderer, tex, &rect, NULL);

	game->entities.player.texture = inter;

	SDL_QueryTexture(inter, NULL, NULL,  &w, &h);
/* 	while (i < 4)
	{
		n = 0;
		while (n < 2)
		{
			game->entities.player.tiles[i][n].x = n * (w / 14);
			game->entities.player.tiles[i][n].y = i * (h / 4);
			n++;
		}
		i++;
	} */
	game->entities.player.hitbox.w = w / 14;
	game->entities.player.hitbox.h = h / 4;
	SDL_SetRenderTarget(game->renderer, NULL);
	/*add death later maybe*/
}

void init_game(Master *game)
{

	int i = 0;

	game->loops[0] = menu_loop;
	game->loops[1] = lvl_loop;
	game->loop = game->loops[0];

	//init_tex(game);

	game->entities.player.parent.friends_and_foes = &game->entities;
}

void init_lvl(Master *game)
{
	init_player(game);
	parse_map(game);
}

void init_menu(Master * game, SDL_Texture *arroX, Vector2 *pos)
{

	SDL_Surface* surface;
	SDL_Rect rect;

	SDL_Texture *inter = SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIN_SIZE, WIN_SIZE);
	SDL_SetRenderTarget(game->renderer, inter);

	/* Build background by combining textures*/
	surface = IMG_Load("imgs/pac-banner.jpg");
	rect.h = WIN_SIZE / 3;
	rect.w = WIN_SIZE;
	rect.x = 0;
	rect.y = 0;
    SDL_Texture* tex = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_RenderCopy(game->renderer, tex, NULL, &rect);

 	surface = IMG_Load("imgs/start_button.png");
	rect.h = WIN_SIZE / 7;
	rect.w = WIN_SIZE / 4;
	rect.x = WIN_SIZE / 3;
	rect.y = WIN_SIZE / 2;
	pos[0].x = rect.x;
	pos[0].y = rect.y;
    tex = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_RenderCopy(game->renderer, tex, NULL, &rect);

	surface = IMG_Load("imgs/exit_button.png");
	rect.h = WIN_SIZE / 7;
	rect.w = WIN_SIZE / 4;
	rect.x = WIN_SIZE / 3;
	rect.y = (WIN_SIZE / 3) * 2;
	pos[1].x = rect.x;
	pos[1].y = rect.y;
    tex = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_RenderCopy(game->renderer, tex, NULL, &rect);

	SDL_SetRenderTarget(game->renderer, NULL);
	game->background = inter;
    SDL_FreeSurface(surface);
}
