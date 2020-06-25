#include "pac.h"

Vector2 parse_input(int input)
{
	Vector2 in;

	if (input == 0)
	{
		in.x = 1;
		in.y = 0;
	}
	else if (input == -1)
	{
		in.x = -1;
		in.y = 0;
	}
	else if (input == 2)
	{
		in.x = 0;
		in.y = 1;
	}
	else if (input == 3)
	{
		in.x = 0;
		in.y = -1;
	}
	else if (input == -1)
	{
		in.x = 0;
		in.y = 0;
	}
	return in;
}

void update_player(Master *game, int input)
{
	Vector2 in;
	SDL_Rect pos;
	int index;

	in = parse_input(input);

	in.x *= game->entities.player.hitbox.w;
	in.y *= game->entities.player.hitbox.h;

	if ((game->entities.player.parent.coordinates.position.x += in.x) < 0)
		game->entities.player.parent.coordinates.position.x = 29;
	else if (game->entities.player.parent.coordinates.position.x + in.x > 29)
		game->entities.player.parent.coordinates.position.x = 29;
	if ((game->entities.player.parent.coordinates.position.y += in.y) < 0)
		game->entities.player.parent.coordinates.position.y = 30;
	else if(game->entities.player.parent.coordinates.position.y + in.y > 30)
		game->entities.player.parent.coordinates.position.y = 0;
	pos.h = WIN_SIZE / 30;
	pos.w = WIN_SIZE / 29;

	if ((index = game->entities.player.parent.tex_index) < 3)

	{
		game->entities.player.hitbox.x = game->entities.player.tiles[input][index].x;
		game->entities.player.hitbox.y = game->entities.player.tiles[input][index].y;
	}

	SDL_RenderCopy(game->renderer, game->entities.player.texture, &game->entities.player.hitbox, &pos);
}
