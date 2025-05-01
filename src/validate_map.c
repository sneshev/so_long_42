#include "so_long.h"

bool only_valid(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1' &&
			map[i] != 'P' && map[i] != 'C' &&
			map[i] != 'E' && map[i] != '\n')
			return (false);
		i++;
	}
	if (map[i - 1] == '\n')
		return (false);
	return (true);
}

bool check_wall_edge(char *map_line, int width)
{
	int j;

	j = 0;
	while (j < width)
	{
		if (map_line[j] != '1')
			return (false);
		j++;
	}
	return (true);
}

bool map_edges(char **map, int width, int height)
{
	int i;

	i = 0;

	if (!check_wall_edge(map[0], width))
		return (false);
	while (i++ < height - 1)
	{
		if (map[i][0] != '1')
			return (false);
		if (map[i][width - 1] != '1')
			return (false);
	}
	if (!check_wall_edge(map[height - 1], width))
		return (false);
	return (true);
}

bool is_rectangular(char *map)
{
	int i;
	int x;
	int count = 0;

	i = 0;
	x = 0;
	while(i <= find(HEIGHT, map))
	{
		x = 0;
		count++;
		while (map[i] && map[i] != '\n')
		{
			i++;
			x++;
		}
		if (find(WIDTH, map) != x)
			return (false);
		i++;
	}
	return (true);
}

bool is_valid(char *map)
{
	char **marrp;

	if (!only_valid(map)) //check for invalid characters
		return (false);
	if (count(map, 'P') != 1 || 	//count players
		count(map, 'E') != 1 ||		//count exits
		count(map, 'C') < 1)		//count collectables
		return (false);
	if (!is_rectangular(map))
		return (false);

	marrp = ft_split(map, '\n');
	if (!map_edges(marrp, find(WIDTH, map), find(HEIGHT, map))) //check sides (ceiling, floor, left and right)
		return (free_arr(marrp), false);
	if (!is_playable(marrp))
		return (free_arr(marrp), false);
	return (free_arr(marrp), true);
}