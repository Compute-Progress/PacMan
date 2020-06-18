#ifndef PAC_H
# define PAC_H

# include <SDL2/SDL.h>
# include "pac_struct.h"
# include <stdio.h>
# include <math.h>

/***** File : level_funcs.c *****/

int menu_loop(Master *game);
int lvl_loop(Master *game);

/*****        ********       *******/

/****** File : init.c */

Master *init_game();
void	init_lvl(Master *game);
void	init_menu(Master *game);

/******* File : render.c *********/

void	draw_background(char *bg);
void	draw_image(char *img, Vector2 positon);


#endif
