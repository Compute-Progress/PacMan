#include "pac.h"

void parse_map(Master *game)
{
	memcpy((&game->entities.map)[ 0], "XXXXXXXXXXXXXXXXXXXXXXXXXXXX", 29);
	memcpy((&game->entities.map)[ 1], "X............XX............X", 29);
	memcpy((&game->entities.map)[ 2], "X.XXXX.XXXXX.XX.XXXXX.XXXX.X", 29);
	memcpy((&game->entities.map)[ 3], "XPXXXX.XXXXX.XX.XXXXX.XXXXPX", 29);
	memcpy((&game->entities.map)[ 4], "X.XXXX.XXXXX.XX.XXXXX.XXXX.X", 29);
	memcpy((&game->entities.map)[ 5], "X..........................X", 29);
	memcpy((&game->entities.map)[ 6], "X.XXXX.XX.XXXXXXXX.XX.XXXX.X", 29);
	memcpy((&game->entities.map)[ 7], "X.XXXX.XX.XXXXXXXX.XX.XXXX.X", 29);
	memcpy((&game->entities.map)[ 8], "X......XX....XX....XX......X", 29);
	memcpy((&game->entities.map)[ 9], "XXXXXX.XXXXX.XX.XXXXX.XXXXXX", 29);
	memcpy((&game->entities.map)[10], "XXXXXX.XXXXX.XX.XXXXX.XXXXXX", 29);
	memcpy((&game->entities.map)[11], "XXXXXX.XX          XX.XXXXXX", 29);
	memcpy((&game->entities.map)[12], "XXXXXX.XX XXXXXXXX XX.XXXXXX", 29);
	memcpy((&game->entities.map)[13], "XXXXXX.XX X      X XX.XXXXXX", 29);
	memcpy((&game->entities.map)[14], "      .   X      X   .      ", 29);
	memcpy((&game->entities.map)[15], "XXXXXX.XX X      X XX.XXXXXX", 29);
	memcpy((&game->entities.map)[16], "XXXXXX.XX XXXXXXXX XX.XXXXXX", 29);
	memcpy((&game->entities.map)[17], "XXXXXX.XX          XX.XXXXXX", 29);
	memcpy((&game->entities.map)[18], "XXXXXX.XX.XXXXXXXX.XX.XXXXXX", 29);
	memcpy((&game->entities.map)[19], "XXXXXX.XX.XXXXXXXX.XX.XXXXXX", 29);
	memcpy((&game->entities.map)[20], "X............XX............X", 29);
	memcpy((&game->entities.map)[21], "X.XXXX.XXXXX.XX.XXXXX.XXXX.X", 29);
	memcpy((&game->entities.map)[22], "X.XXXX.XXXXX.XX.XXXXX.XXXX.X", 29);
	memcpy((&game->entities.map)[23], "XP..XX.......  .......XX..PX", 29);
	memcpy((&game->entities.map)[24], "XXX.XX.XX.XXXXXXXX.XX.XX.XXX", 29);
	memcpy((&game->entities.map)[25], "XXX.XX.XX.XXXXXXXX.XX.XX.XXX", 29);
	memcpy((&game->entities.map)[26], "X......XX....XX....XX......X", 29);
	memcpy((&game->entities.map)[27], "X.XXXXXXXXXX.XX.XXXXXXXXXX.X", 29);
	memcpy((&game->entities.map)[28], "X.XXXXXXXXXX.XX.XXXXXXXXXX.X", 29);
	memcpy((&game->entities.map)[29], "X..........................X", 29);
	memcpy((&game->entities.map)[30], "XXXXXXXXXXXXXXXXXXXXXXXXXXXX", 29);

	game->entities.player.parent.coordinates.position.x = 14;
	game->entities.player.parent.coordinates.position.y = 23;

}
