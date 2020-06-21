#include "pac.h"
/*
Ghost *init_ghost(Master *game)
{
	int i = 0;

	game->entities->ghost[0]->parent.coorddinates.position.x = 0;

}
 */
void init_game(Master *game)
{

	int i = 0;
	int w, h;
	SDL_Surface *surf;


	game->state = 0;
	game->entities = malloc(sizeof(Entities));

	game->entities->player = malloc (sizeof(Player));
	while (i < 4)
	{
		game->entities->ghost[i] = malloc(sizeof(Ghost));
		i++;
	}


	game->loops[0] = menu_loop;
	game->loops[1] = lvl_loop;
	game->loop = game->loops[0];
}

void init_lvl(Master *game)
{

}

void init_menu(Master * game, SDL_Texture *arrow, Vector2 *pos)
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
    tex = SDL_CreateTextureFromSurface(game->renderer, surface);
	pos[0].x = rect.x;
	pos[0].y = rect.y;
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

	printf("STart\n");
//	SDL_RenderPresent(game->renderer);
	SDL_SetRenderTarget(game->renderer, NULL);
	game->background = inter;
	printf("End\n");
    SDL_FreeSurface(surface);

    SDL_Rect dest;
}
