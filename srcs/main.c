#include "pac.h"

int main()
{
	Master Game;
	int new_state = 0;

	//Game = malloc(sizeof(Master));
	init_game(&Game);
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error %s\n", SDL_GetError());
	Uint32 render_flags = SDL_RENDERER_SOFTWARE;
	Game.window = SDL_CreateWindow("Pac_Man", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_SIZE, WIN_SIZE, 0);
	Game.renderer = SDL_CreateRenderer(Game.window, -1, render_flags);
	while (1)
	{
		//menu_loop(&Game);
		 if ((new_state = Game.loop(&Game)) == 3)
			break ;
		Game.loop = Game.loops[new_state];
	}
	/* Cleanup function goes here*/
}
