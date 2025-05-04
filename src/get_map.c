# include "../gnl/get_next_line.h"
#include "so_long.h"

char *find_map(char *name, int free_flag)
{
	char *dot;
	char *temp;

	dot = ft_strrchr(name, '.');
	if (!dot || ft_strncmp(dot, ".ber", 5))
	{
		// temp = ft_strjoin(name, ".ber");
		// if (!temp)
		return (NULL);
		// return (find_map(temp, 1));
	}
	temp = ft_strjoin("maps/", name);
	if (!temp)
		return (NULL);
	if (free_flag)
		free(name);
	return (temp);
}

char *getmap(char *name)
{
	int fd;
	char *red;
	char *map = NULL;

	map = find_map(name, 0);
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
