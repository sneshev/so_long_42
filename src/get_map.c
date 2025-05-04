# include "../utils/get_next_line.h"
#include "so_long.h"

char *find_map(char *name)
{
	char *dot;
	char *temp;

	dot = ft_strrchr(name, '.');
	if (!dot || ft_strncmp(dot, ".ber", 5))
		return (NULL);
	temp = ft_strjoin("maps/", name);
	if (!temp)
		return (NULL);
	return (temp);
}

char *getmap(char *name)
{
	int fd;
	char *red;
	char *map = NULL;

	map = find_map(name);
	fd = open(map, O_RDONLY);
	free(map);
	map = NULL;
	if (fd == -1)
		return (NULL);

	red = get_next_line(fd);
	while (red)
	{
		map = add_to_line(&map, &red);
		red = get_next_line(fd);
	}
	return (map);
}
