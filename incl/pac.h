#ifndef PAC_H
# define PAC_H

# include "SDL.h"
# include "SDL_image.h"
# include "pac_struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define WIN_SIZE 500
# define CELL_W WIN_SIZE / 29
# define CELL_H WIN_SIZE / 28

/***** File : level_funcs.c *****/

int		menu_loop(Master *game);
int		lvl_loop(Master *game);

/****** File : init.c */
void	init_game(Master *game);
void	init_lvl(Master *game);
void	init_player(Master *game);
void	init_menu(Master *game, SDL_Texture *arrow, Vector2* pos);

/******* File : updates.x  *******/
void	update_player(Master *game, int *input);
void	update_ghosts(Master *game);

/******* File: render.c   *******/
void	draw_map_bg(Master *game);
void	draw_items(Master *game);

/******* File: parse.c   ********/
void	parse_map(Master *game);
Vector2 parse_input(int input);

/******* File: ghosts.c ********/
Vector2 blinky(Master *game);
Vector2 pinky(Master *game);
Vector2 inky(Master *game);
Vector2 clyde(Master *game);
Vector2 dead(Ghost *ghost);
Vector2 frightened(Ghost *ghost);
#endif
