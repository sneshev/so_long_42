#include "so_long.h"

int is_valid_name(char *name)
{
	if (!name)
		return 0;
	return 1;	
}

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

	if (!is_valid_name(name))
		return (NULL);
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

void free_arr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = 0;
	while(arr[i])
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}

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