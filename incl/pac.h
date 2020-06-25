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

/******* File : render.c *********/

void	draw_background(char *bg);
void	draw_image(char *img, Vector2 positon);

/******* File : updates.x *******/
void	update_player(Master *game, int input);

void parse_map(Master *game);

#endif
