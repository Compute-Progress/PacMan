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

	target.x = game->entities.player.parent.coordinates.position.x;
	target.y = game->entities.player.parent.coordinates.position.y;
	target.x += game->entities.player.parent.coordinates.direction.x * 2;
	target.y += game->entities.player.parent.coordinates.direction.y * 2;

	target.x = game->entities.ghost[0].parent.coordinates.position.x - target.x;
	target.y = game->entities.ghost[0].parent.coordinates.position.y - target.y;
	target.x *= -1;
	target.y *= -1;
	return target;
}

Vector2 clyde(Master *game)
{
	Vector2 target;
	double distance;

	distance = pow(game->entities.ghost[0].parent.coordinates.position.x - game->entities.player.parent.coordinates.position.x, 2) +
	pow(game->entities.ghost[0].parent.coordinates.position.y - game->entities.player.parent.coordinates.position.y, 2);

	if (sqrt(distance) > 8)
		return game->entities.player.parent.coordinates.position;
	else
		return game->entities.ghost[0].target;
}
