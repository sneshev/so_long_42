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