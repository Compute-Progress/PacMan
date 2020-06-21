#include "pac.h"

int menu_loop(Master *game)
{
	SDL_Texture *arrow_tex;
	SDL_Surface *surface;
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
				switch (event.key.keysym.scancode)
				{
					default :
						break ;
					case SDL_SCANCODE_UP:
						(index == 1) ? (index = 0) : (index = 1);
					case SDL_SCANCODE_DOWN:
						(index == 0) ? (index = 1) : (index = 0);
					case SDL_SCANCODE_SPACE:
						if (index == 0)
							return 1;
						else return 3;
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

/* int lvl_loop(Master *game)
{

} */
