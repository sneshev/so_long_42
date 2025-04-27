#include "so_long.h"

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

int find(int attrib, char *map)
{
	int count;

	count = 1;
	if (attrib == WIDTH)
	{
		while (map[count] && map[count] != '\n')
			count++;
		return (count);
	}
	else if (attrib == HEIGHT)
	{
		while(*(map++))
		{
			if (*map == '\n')
				count++;
		}
		return (count);
	}
	else { printf("wtffff broo...") ;}
	return (1);
}
