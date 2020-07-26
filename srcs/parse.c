#include "pac.h"

void parse_map(Master *game)
{
	SDL_Surface *surf;

	memcpy((game->entities.map)[ 0], "2111111111111221111111111112", 29);
	memcpy((game->entities.map)[ 1], "0............00............0", 29);
	memcpy((game->entities.map)[ 2], "0.2112.21112.00.21112.2112.0", 29);
	memcpy((game->entities.map)[ 3], "0#0  0.0   0.00.0   0.0  0#0", 29);
	memcpy((game->entities.map)[ 4], "0.2112.21112.22.21112.2112.0", 29);
	memcpy((game->entities.map)[ 5], "0..........................0", 29);
	memcpy((game->entities.map)[ 6], "0.2112.22.21111112.22.2112.0", 29);
	memcpy((game->entities.map)[ 7], "0.2112.00.21122112.00.2112.0", 29);
	memcpy((game->entities.map)[ 8], "0......00....00....00......0", 29);
	memcpy((game->entities.map)[ 9], "211112.02112.00.21120.211112", 29);
	memcpy((game->entities.map)[10], "0    0.02112.22.21120.2    0", 29);
	memcpy((game->entities.map)[11], "0    0.00          00.2    0", 29);
	memcpy((game->entities.map)[12], "0    0.00 211  112 00.2    0", 29);
	memcpy((game->entities.map)[13], "211112.22 0      0 22.211112", 29);
	memcpy((game->entities.map)[14], "      .   0      0   .      ", 29);
	memcpy((game->entities.map)[15], "211112.22 0      0 22.211112", 29);
	memcpy((game->entities.map)[16], "0    0.00 21111112 00.0    0", 29);
	memcpy((game->entities.map)[17], "0    0.00          00.0    0", 29);
	memcpy((game->entities.map)[18], "0    0.00.21111112.00.0    0", 29);
	memcpy((game->entities.map)[19], "211112.22.21122112.22.211112", 29);
	memcpy((game->entities.map)[20], "0............00............0", 29);
	memcpy((game->entities.map)[21], "0.2112.21112.00.21112.2112.0", 29);
	memcpy((game->entities.map)[22], "0.2120.21112.22.21112.0212.0", 29);
	memcpy((game->entities.map)[23], "0#..00.......  .......00..#0", 29);
	memcpy((game->entities.map)[24], "212.00.22.21111112.22.00.212", 29);
	memcpy((game->entities.map)[25], "212.22.00.21122112.00.22.212", 29);
	memcpy((game->entities.map)[26], "0......00....00....00......0", 29);
	memcpy((game->entities.map)[27], "0.2111122112.00.2112211112.0", 29);
	memcpy((game->entities.map)[28], "0.2111111112.22.2111111112.0", 29);
	memcpy((game->entities.map)[29], "0..........................0", 29);
	memcpy((game->entities.map)[30], "0111111111111111111111111110", 29);
	game->entities.player.parent.coordinates.position.x = 14;
	game->entities.player.parent.coordinates.position.y = 23;
	draw_map_bg(game);
}

Vector2 parse_input(int input)
{
	Vector2 in;

	if (input == 0)
	{
		in.x = 1;
		in.y = 0;
	}
	else if (input == 1)
	{
		in.x = -1;
		in.y = 0;
	}
	else if (input == 3)
	{
		in.x = 0;
		in.y = 1;
	}
	else if (input == 2)
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
