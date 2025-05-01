#include "so_long.h"

int main(int argc, char *argv[])
{
	// int argc = 2;
	// char *argv[2] = {"./so_long", "heart.ber"};
	char *map;

	if (argc != 2)
		return (printf("add good args"), -1);
	map = getmap(argv[1]);
	if (map == NULL)
		return (printf("invalid map name"), -1);
	
	if (!is_valid(map))
		return (free(map), printf("invalid map"), -1);
	
	start_game(map);

	//free the t_game and its contents
	free(map);
}
