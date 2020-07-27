#include "pac.h"

int menu_loop(Master *game)
{
	SDL_Texture *arrow_tex;
	SDL_Surface *surface;
	SDL_Scancode input;
	SDL_Rect arrow;
	Vector2 pos[2];
	int index;

	init_menu(game, arrow_tex, pos);
	index = 0;

	surface = IMG_Load("imgs/red_arrow.png");
	arrow_tex = SDL_CreateTextureFromSurface(game->renderer, surface);
	arrow.h = WIN_SIZE / 6;
	arrow.w = WIN_SIZE / 6;
	arrow.x = pos[0].x - arrow.w;
	arrow.y = pos[0].y;
    while (1) {
        SDL_Event event;

        // Events mangement
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
				exit(0);
			case SDL_KEYDOWN :
				input = event.key.keysym.scancode;

					if (input == SDL_SCANCODE_UP)
						(index == 1) ? (index = 0) : (index = 1);
					else if (input == SDL_SCANCODE_DOWN)
						(index == 0) ? (index = 1) : (index = 0);
					else if (input == SDL_SCANCODE_SPACE)
					{
						if (index == 0)
							return 1;
						else exit(0);
					}
            }
        }
		arrow.y = pos[index].y;
        SDL_RenderClear(game->renderer);
        SDL_RenderCopy(game->renderer, game->background, NULL, NULL);
        SDL_RenderCopy(game->renderer, arrow_tex, NULL, &arrow);
		SDL_RenderPresent(game->renderer);
    }
}

int lvl_loop(Master *game)
{
	init_lvl(game);
	int input = -1, run = 1;
	SDL_Scancode in;
	while (1)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
            switch (e.type) {

            case SDL_QUIT:
				exit(0);
			case SDL_KEYDOWN :
				in = e.key.keysym.scancode;
				if (in == SDL_SCANCODE_UP)
					input = 2;
				else if (in == SDL_SCANCODE_DOWN)
					input = 3;
				else if (in == SDL_SCANCODE_RIGHT)
					input = 0;
				else if (in == SDL_SCANCODE_LEFT)
					input = 1;
			}
        }
		if (run == 1)
		{
			SDL_RenderClear(game->renderer);
			SDL_RenderCopy(game->renderer, game->background, NULL, NULL);
			update_player(game, &input);
			update_ghosts(game);
			SDL_RenderPresent(game->renderer);
			if (game->invicibility > 0)
				game->invicibility--;
			if (game->lives <= 0 || game->pellets <= 0)
			{
				run = 0;
				printf("Score : %d, Lives %d\n", game->score, game->lives);
			}
		}
		SDL_Delay(200);
	}
}
