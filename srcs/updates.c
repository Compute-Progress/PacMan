#include "pac.h"

void handle_collisions(Master *game, Vector2 input, int *dir)
{
	Vector2 vec = game->entities.player.parent.coordinates.direction;
	char c;

	if (game->entities.map[game->entities.player.parent.coordinates.position.y + input.y]
	[game->entities.player.parent.coordinates.position.x + input.x] < '0')
		vec = input;
	else
		*dir = game->entities.player.parent.dir;
	if ((c = game->entities.map[game->entities.player.parent.coordinates.position.y + vec.y]
		[game->entities.player.parent.coordinates.position.x + vec.x]) < '0')
	{
		if (c == '.')
		{
			game->entities.map[game->entities.player.parent.coordinates.position.y + vec.y]
			[game->entities.player.parent.coordinates.position.x + vec.x] = ' ';
			game->pellets--;
			game->score += 100;
		}
		if ((game->entities.player.parent.coordinates.position.x += vec.x) < 0)
			game->entities.player.parent.coordinates.position.x = 29;
		else if (game->entities.player.parent.coordinates.position.x > 28)
			game->entities.player.parent.coordinates.position.x = 0;
		if ((game->entities.player.parent.coordinates.position.y += vec.y) < 0)
			game->entities.player.parent.coordinates.position.y = 30;
		else if(game->entities.player.parent.coordinates.position.y > 30)
			game->entities.player.parent.coordinates.position.y = 0;
	}
	game->entities.player.parent.coordinates.direction = vec;
}

void update_player(Master *game, int *input)
{
	Vector2 in;
	SDL_Rect pos;
	int index;

	in = parse_input(*input);

	handle_collisions(game, in, input);
	pos.h = WIN_SIZE / 25;
	pos.w = WIN_SIZE / 24;
	pos.x = game->entities.player.parent.coordinates.position.x * WIN_SIZE / 29;
	pos.y = game->entities.player.parent.coordinates.position.y * WIN_SIZE / 30;

if (*input >= 0)
{
	if ((index = game->entities.player.parent.tex_index) < 2)
	{
		game->entities.player.parent.tex_index++;
		game->entities.player.hitbox.y = *input * game->entities.player.hitbox.h;
	}
	else
	{
		game->entities.player.parent.tex_index = 0;
		game->entities.player.hitbox.y = 0;
	}
}
	game->entities.player.hitbox.x = index * game->entities.player.hitbox.w;
	SDL_RenderCopy(game->renderer, game->entities.player.texture, &game->entities.player.hitbox, &pos);
	game->entities.player.parent.dir = *input;
	draw_items(game);
}
