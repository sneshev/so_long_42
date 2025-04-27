#include "so_long.h"

void print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("map[%d]: %s\n", i, map[i]);
		i++;
	}
}