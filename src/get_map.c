#include "so_long.h"

char *find_map(char *name, int free_flag)
{
	char *dot;
	char *temp;

	dot = strrchr(name, '.');
	if (!dot || strncmp(dot, ".ber", 5))
	{
		temp = ft_strjoin(name, ".ber");
		if (!temp)
			return (NULL);
		return (find_map(temp, 1));
	}
	temp = ft_strjoin("maps/", name);
	if (!temp)
		return (NULL);
	if (free_flag)
		free(name);
	return (temp);
}

char **getmap(char *name)
{
	int fd;
	char *red;
	char *temp = NULL;
	char **map;

	temp = find_map(name, 0);
	fd = open(temp, O_RDONLY);
	free(temp);
	temp = NULL;
	if (fd == -1)
		return (NULL);

	red = get_next_line(fd);
	while (red)
	{
		temp = add_to_line(&temp, &red);
		red = get_next_line(fd);
	}
	map = ft_split(temp, '\n');
	return (free(temp), map);
}