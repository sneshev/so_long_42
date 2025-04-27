#include "so_long.h"

// int find(char *attrib, char *map)
// {
// 	int count;

// 	count = 1;
// 	if (ft_strncmp(attrib, "width", 5) == 0)
// 	{
// 		while (map[count] && map[count] != '\n')
// 			count++;
// 		return (count);
// 	}
// 	else if (ft_strncmp(attrib, "height", 6) == 0)
// 	{
// 		while(*(map++))
// 		{
// 			if (*map == '\n')
// 				count++;
// 		}
// 		return (count);
// 	}
// 	else { printf("wtffff broo...") ;}
// 	return (1);
// }

// void game()
// {
// 	mlx_t *mlx;
// 	if (!(mlx = mlx_init(find("width", argv[1]), find("height", argv[1]), "idk", false)))
// 	{
// 		puts();
// 		return (1);
// 	}
// }


int main()
{
	int argc = 2;
	char *argv[2] = {"./so_long", "base"};
	char **map;

	if (argc != 2)
		return (printf("add good args"), -1);
	map = getmap(argv[1]);
	if (map == NULL)
		return (printf("invalid map name"), -1);
	
	print_map(map);
	free_arr(map);
}