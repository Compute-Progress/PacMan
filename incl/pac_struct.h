#ifndef PAC_STRUCT_H
# define PAC_STRUCT_H

struct s_game_state;

typedef struct  s_game_state Master;

typedef int(*state_update)(Master*);

struct s_entities;

typedef struct s_entities Entities;

typedef struct s_Vector2
{
    int x, y;
}              Vector2;

typedef struct s_coordinates
{
	Vector2 position;
	Vector2 direction;
}				Coordinates;

typedef Vector2(*calc_target)(Master *game);

typedef struct s_pawn
{
	Coordinates coordinates;

	int dir, tex_index;
}				Pawn;

typedef struct s_ghost
{
	Pawn parent;
	calc_target target_func;
	int state, timer;

	Vector2 target;
	SDL_Rect source;
}				Ghost;

typedef struct s_player
{
	Pawn parent;

	SDL_Texture *texture;
	SDL_Rect hitbox;
}				Player;

struct s_entities
{
	Ghost  ghost[4];
	Player player;

	char map[31][30];
	SDL_Texture *ghost_tex;
};

struct  s_game_state
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *background;

	Entities entities;
	state_update loops[4];
	state_update loop;
	int pellets, score, lives;
};

#endif
