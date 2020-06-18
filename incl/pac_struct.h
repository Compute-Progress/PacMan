#ifndef PAC_STRUCT_H
# define PAC_STRUCT_H

typedef int(*state_update)();

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

typedef void(*ghost_update)(Entities entities, Coordinates coord, Vector2 target);

typedef struct s_pawn
{
    char **map;
	char *texture;
	Coordinates coorddinates;
}				Pawn;

typedef struct s_player
{
	Pawn parent;
	struct moving_pawns *friends_and_foes;
    int state;
}				Player;

typedef struct s_ghost
{
	Pawn parent;
	Vector2 target;
}				Ghost;

struct s_entities
{
	Ghost  *ghost[4];
	Player *player;
};

typedef struct  s_game_state
{
	Entities *entities;
	int state;
    char *render;
	state_update loops[4];
	state_update loop;
}               Master;

#endif
