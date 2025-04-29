#include "so_long.h"



// void start_game(char *map)
// {
// 	mlx_t *mlx;
// 	if (!(mlx = mlx_init(find("width", map), find("height", map), "idk", false)))
// 	{
// 		// puts();
// 		return (1);
// 	}
// }


int main(int argc, char *argv[])
{
	// int argc = 2;
	// char *argv[2] = {"./so_long", "invalid19.ber"};
	char *map;

	if (argc != 2)
		return (printf("add good args"), -1);
	map = getmap(argv[1]);
	if (map == NULL)
		return (printf("invalid map name"), -1);
	
	print_map(map);

	if (!is_valid(map))
		return (free(map), printf("invalid map"), -1);
	
	printf("mapp good :)");
	
	// start_game(map);

	free(map);
}