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
			game->score += 10;
		}
		else if (c == '#')
		{
			if (game->entities.ghost[0].state != 1)
			{
				game->entities.ghost[0].state = 0;
				game->entities.ghost[0].timer = 0;
			}
			if (game->entities.ghost[1].state != 1)
			{
				game->entities.ghost[1].state = 0;
				game->entities.ghost[1].timer = 0;
			}
			if (game->entities.ghost[2].state != 1)
			{
				game->entities.ghost[2].state = 0;
				game->entities.ghost[2].timer = 0;
			}
			if (game->entities.ghost[3].state != 1)
			{
				game->entities.ghost[3].state = 0;
				game->entities.ghost[3].timer = 0;
			}
			game->entities.map[game->entities.player.parent.coordinates.position.y + vec.y]
			[game->entities.player.parent.coordinates.position.x + vec.x] = ' ';
		}
		if ((game->entities.player.parent.coordinates.position.x += vec.x) < 0)
			game->entities.player.parent.coordinates.position.x = 28;
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
	pos.x = game->entities.player.parent.coordinates.position.x * CELL_W;
	pos.y = game->entities.player.parent.coordinates.position.y * CELL_H - (CELL_H);

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

int try_dir(Master *game, Vector2 newdir, Coordinates coord, Vector2 target, int state)
{
	int c;

	if ((coord.direction.x + newdir.x) != 0 || (coord.direction.y + newdir.y) != 0)
	{
		int x = coord.position.x + newdir.x;
		int y = coord.position.y + newdir.y;
		if (newdir.y == 1 && game->entities.map[y][x] == '!' && state != 1)
			return -1;
		if (game->entities.map[y][x] < '0' && x > 0 && y  > 0)
		{
			c = (int)(pow(target.x - x, 2) + pow(target.y - y, 2));
			return c;
		}
	}
	return -1;
}

void move_ghost(Master *game, Ghost *ghost, Vector2 target)
{
	int c;
	int result = INT32_MAX;
	Coordinates co = ghost->parent.coordinates;
	Vector2 new_dir, direction;

	if (co.position.x == game->entities.player.parent.coordinates.position.x &&
	co.position.y == game->entities.player.parent.coordinates.position.y)
	{
		if (ghost->state == 0)
			ghost->state = 1;
		if (ghost->state == 2 && game->invicibility <= 0)
		{
			game->lives--;
			game->invicibility = 10;
			printf("Lives %d\n", game->lives);
		}
	}
	direction = co.direction;
	new_dir.y = 0;
	new_dir.x = -1;
	c = try_dir(game, new_dir, co, target, ghost->state);
	if (c < result && c > 0)
	{
		result = c;
		direction = new_dir;
	}
	new_dir.y = 0;
	new_dir.x = 1;
	c = try_dir(game, new_dir, co, target, ghost->state);
	if (c < result && c > 0)
	{
		result = c;
		direction = new_dir;
	}
	new_dir.y = 1;
	new_dir.x = 0;
	c = try_dir(game, new_dir, co, target, ghost->state);
	if (c < result && c > 0)
	{
		result = c;
		direction = new_dir;
	}
	new_dir.y = -1;
	new_dir.x = 0;
	c = try_dir(game, new_dir, co, target, ghost->state);
	if (c <= result && c > 0)
	{
		result = c;
		direction = new_dir;
	}

	co.direction = direction;
	co.position.x += direction.x;
	co.position.y += direction.y;
	if (co.position.x < 0)
		co.position.x = 28;
	if (co.position.x > 28)
		co.position.x = 0;
	if (co.position.x == game->entities.player.parent.coordinates.position.x &&
	co.position.y == game->entities.player.parent.coordinates.position.y)
	{
		if (ghost->state == 0)
			ghost->state = 1;
		if (ghost->state == 2 && game->invicibility <= 0)
		{
			game->lives--;
			game->invicibility = 20;
			printf("Lives %d\n", game->lives);
		}
	}
	ghost->parent.coordinates = co;
	SDL_RenderDrawLine(game->renderer, co.position.x * CELL_W, co.position.y * CELL_H, target.x * CELL_W, target.y * CELL_H);
	if (direction.x == 0)
	{
		(direction.y == 1) ? (ghost->parent.dir = 3) : (ghost->parent.dir = 2);
	}
	else
		(direction.x == 1) ? (ghost->parent.dir = 0) : (ghost->parent.dir = 1);
}

void  render_ghost(Master*game, Ghost *ghost, int number)
{
	SDL_Rect pos;
	int max;

	pos.h = WIN_SIZE / 25;
	pos.w = WIN_SIZE / 24;
	pos.x = ghost->parent.coordinates.position.x * CELL_W ;
	pos.y = ghost->parent.coordinates.position.y * CELL_H - CELL_H;

	(ghost->state == 2) ? (ghost->source.y = number) : (ghost->source.y = ghost->state);
	ghost->source.y *= ghost->source.h;
	if (ghost->state != 2)
	{
		ghost->source.x = 8;
	}
	if (ghost->state == 2)
	{
		ghost->source.x = ghost->parent.dir * ghost->state;
	}
	if (ghost->state == 0)
		ghost->source.x += ghost->parent.dir;
	if (ghost->state != 1)
	{
		ghost->source.x += ghost->parent.tex_index;
		(ghost->parent.tex_index == 1) ? (ghost->parent.tex_index = 0) : (ghost->parent.tex_index = 1);
	}
	ghost->source.x *= ghost->source.w;
	SDL_RenderCopy(game->renderer, game->entities.ghost_tex, &ghost->source, &pos);
}

void update_ghosts(Master *game)
{
	int i = 0;
	Vector2 target;

	while (i < 4)
	{
		if (game->entities.ghost[i].state == 2)
		{
			target = game->entities.ghost[i].target_func(game);
		}
		else if (game->entities.ghost[i].state == 1)
			target = dead(&game->entities.ghost[i]);
		else
			target = frightened(&game->entities.ghost[i]);
		move_ghost(game, &game->entities.ghost[i], target);
		render_ghost(game, &game->entities.ghost[i], i);
		i++;
	}
}
