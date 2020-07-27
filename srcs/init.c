#include "pac.h"

void init_ghost(Master *game)
{

	int w, h;
	SDL_Surface *surf;
	SDL_Texture *tex;
	SDL_Texture *inter;
	SDL_Rect rect;

	surf = IMG_Load("imgs/SpriteSheet.png");
	inter = SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIN_SIZE, WIN_SIZE);
	tex = SDL_CreateTextureFromSurface(game->renderer, surf);
	SDL_SetRenderTarget(game->renderer, inter);

	SDL_QueryTexture(tex, NULL, NULL,  &w, &h);


	rect.y = (h / 10) * 4;
	rect.x  = 5;
	rect.h = (h / 10) * 4;
	rect.w = w;

	SDL_RenderCopy(game->renderer, tex, &rect, NULL);
	SDL_SetRenderTarget(game->renderer, NULL);
	game->entities.ghost_tex = inter;
	SDL_QueryTexture(inter, NULL, NULL,  &w, &h);
	game->entities.ghost[0].parent.coordinates.position.x = 26;
	game->entities.ghost[0].parent.coordinates.position.y = 1;
	game->entities.ghost[0].target.y = -1;
	game->entities.ghost[0].target.x = 26;
	game->entities.ghost[0].parent.coordinates.direction.x = 1;
	game->entities.ghost[0].parent.coordinates.direction.y = 0;
	game->entities.ghost[0].source.w = w / 14;
	game->entities.ghost[0].source.h = h / 4;
	game->entities.ghost[0].state = 2;
	game->entities.ghost[0].parent.tex_index = 0;
	game->entities.ghost[0].target_func = &blinky;

	game->entities.ghost[1].parent.coordinates.position.x = 1;
	game->entities.ghost[1].parent.coordinates.position.y = 1;
	game->entities.ghost[1].target.y = -1;
	game->entities.ghost[1].target.x = 1;
	game->entities.ghost[1].parent.coordinates.direction.x = 1;
	game->entities.ghost[1].parent.coordinates.direction.y = 0;
	game->entities.ghost[1].source.w = w / 14;
	game->entities.ghost[1].source.h = h / 4;
	game->entities.ghost[1].state = 2;
	game->entities.ghost[1].parent.tex_index = 0;
	game->entities.ghost[1].target_func = &pinky;

	game->entities.ghost[2].parent.coordinates.position.x = 26;
	game->entities.ghost[2].parent.coordinates.position.y = 29;
	game->entities.ghost[2].target.y = 31;
	game->entities.ghost[2].target.x = 26;
	game->entities.ghost[2].parent.coordinates.direction.x = 1;
	game->entities.ghost[2].parent.coordinates.direction.y = 0;
	game->entities.ghost[2].source.w = w / 14;
	game->entities.ghost[2].source.h = h / 4;
	game->entities.ghost[2].state = 2;
	game->entities.ghost[2].parent.tex_index = 0;
	game->entities.ghost[2].target_func = &inky;

	game->entities.ghost[3].parent.coordinates.position.x = 1;
	game->entities.ghost[3].parent.coordinates.position.y = 29;
	game->entities.ghost[3].target.y = 31;
	game->entities.ghost[3].target.x = 1;
	game->entities.ghost[3].parent.coordinates.direction.x = 1;
	game->entities.ghost[3].parent.coordinates.direction.y = 0;
	game->entities.ghost[3].source.w = w / 14;
	game->entities.ghost[3].source.h = h / 4;
	game->entities.ghost[3].state = 2;
	game->entities.ghost[3].parent.tex_index = 0;
	game->entities.ghost[3].target_func = &clyde;
}

void init_player(Master *game)
{
	int w, h;
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
	rect.x = 4;
	rect.y = 0;
	SDL_RenderCopy(game->renderer, tex, &rect, NULL);

	game->entities.player.texture = inter;

	SDL_QueryTexture(inter, NULL, NULL,  &w, &h);
	game->entities.player.hitbox.w = w / 14;
	game->entities.player.hitbox.h = h / 4;
	SDL_SetRenderTarget(game->renderer, NULL);

	game->invicibility = 0;
	/*add death later maybe*/
}

void init_game(Master *game)
{
	game->loops[0] = menu_loop;
	game->loops[1] = lvl_loop;
	game->loop = game->loops[0];
	game->pellets = 260;
	game->lives = 3;
}

void init_lvl(Master *game)
{
	init_player(game);
	init_ghost(game);
	parse_map(game);
}

void init_menu(Master * game, Vector2 *pos)
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
