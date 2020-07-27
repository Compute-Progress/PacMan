#include "pac.h"

Vector2 blinky(Master *game)
{
	return game->entities.player.parent.coordinates.position;
}

Vector2 pinky(Master *game)
{
	Vector2 target;

	target.x = game->entities.player.parent.coordinates.position.x;
	target.y = game->entities.player.parent.coordinates.position.y;
	target.x += game->entities.player.parent.coordinates.direction.x * 4;
	target.y += game->entities.player.parent.coordinates.direction.y * 4;
	return target;
}

Vector2 inky(Master *game)
{
	Vector2 target;
	int x, y;

	target.x = game->entities.player.parent.coordinates.position.x;
	target.y = game->entities.player.parent.coordinates.position.y;
	target.x += game->entities.player.parent.coordinates.direction.x * 2;
	target.y += game->entities.player.parent.coordinates.direction.y * 2;

	x = game->entities.ghost[0].parent.coordinates.position.x - target.x;
	y = game->entities.ghost[0].parent.coordinates.position.y - target.y;
	target.x -= x;
	target.y -= y;
	return target;
}

Vector2 clyde(Master *game)
{
	Vector2 target;
	double distance;

	distance = pow(game->entities.ghost[3].parent.coordinates.position.x - game->entities.player.parent.coordinates.position.x, 2) +
	pow(game->entities.ghost[3].parent.coordinates.position.y - game->entities.player.parent.coordinates.position.y, 2);

	if (sqrt(distance) > 8)
		return game->entities.player.parent.coordinates.position;
	else
		return game->entities.ghost[3].target;
}

Vector2 frightened(Ghost *ghost)
{
	Vector2 dir;

	dir.x = rand() % 29;
	dir.y = rand() % 30;
	ghost->timer++;
	if (ghost->timer > 50)
		ghost->state = 2;
	return dir;
}

Vector2 dead(Ghost *ghost)
{
	Vector2 dir;
	static int reached;
	dir.x = 14;
	if (ghost->parent.coordinates.position.x == 14 &&
	ghost->parent.coordinates.position.y == 13)
	{
		reached = 1;
	}
	if (reached == 0)
		dir.y = 13;
	if (reached == 	1)
	{
		if (ghost->parent.coordinates.position.x == 14 &&
		ghost->parent.coordinates.position.y == 11)
		{
			ghost->state = 2;
			dir.y = 10;
		}
		else dir.y = 11;
	}
	return dir;
}
