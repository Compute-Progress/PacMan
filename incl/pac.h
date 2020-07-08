#ifndef PAC_H
# define PAC_H

# include "SDL.h"
# include "SDL_image.h"
# include "pac_struct.h"
# include <stdio.h>
# include <math.h>

#define WIN_SIZE 500

/***** File : level_funcs.c *****/

int menu_loop(Master *game);
int lvl_loop(Master *game);

/*****        ********       *******/

/****** File : init.c */
void	init_game(Master *game);
void	init_lvl(Master *game);
void init_player(Master *game);
void	init_menu(Master *game, SDL_Texture *arrow, Vector2* pos);

/******* File : updates.x *******/
void	update_player(Master *game, int *input);

/******* File: render.c *******/
void draw_map_bg(Master *game);

void parse_map(Master *game);

#endif
