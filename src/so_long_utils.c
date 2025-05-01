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

void cleanup(t_game *game, t_player *player, mlx_t *mlx)
{
	if (game)
	{
		if (game->map)
			free_arr(game->map);
		free(game);
	}

	if (player)
	{
		if (player->img)
			mlx_delete_image(mlx, player->img);
		free(player);
	}

	if (mlx)
		mlx_terminate(mlx);
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
			if (*map == '\n' && *(map + 1) && *(map + 1) != '\n')
				count++;
		}
		return (count);
	}
	else { printf("wtffff broo...") ;}
	return (1);
}

int count(char *map, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == c)
			count++;
		i++;;
	}
	return (count);
}

// mlx_image_t *get_image(int type, mlx_t *mlx)
// {
// 	mlx_texture_t *tex = NULL;

// 	if (type == WALL)
// 		tex = mlx_load_png("images/rock.png");
// 	else if (type == PLAYER)
// 		tex = mlx_load_png("images/spirit.png");
// 	else if (type == COLLECTIBLE)
// 		tex = mlx_load_png("images/skull.png");
// 	else if (type == EXIT)
// 		tex = mlx_load_png("images/portal.png");
// 	else if (type == EMPTY)
// 		tex = mlx_load_png("images/grass.png");

// 	if (!tex)
// 	{
// 		printf("Failed to load texture for type %d\n", type);
// 		return NULL;
// 	}

// 	mlx_image_t *img = mlx_texture_to_image(mlx, tex);
// 	// mlx_delete_texture(tex); // cleanup after image created
// 	return img;
// }

mlx_image_t *get_image(int type, mlx_t *mlx)
{
	mlx_texture_t* wall_tex;
	mlx_texture_t* floor_tex;
	mlx_texture_t* player_tex;
	mlx_texture_t* exit_tex;
	mlx_texture_t* collect_tex;

	wall_tex = mlx_load_png("images/rock.png");
	floor_tex = mlx_load_png("images/grass.png");
	player_tex = mlx_load_png("images/spirit.png");
	exit_tex = mlx_load_png("images/portal.png");
	collect_tex = mlx_load_png("images/skull.png");
	if (!mlx)
		return (NULL);
	if (type == WALL)
		return (mlx_texture_to_image(mlx, wall_tex));
	if (type == PLAYER)
		return (mlx_texture_to_image(mlx, player_tex));
	if (type == COLLECTIBLE)
		return (mlx_texture_to_image(mlx, collect_tex));
	if (type == EXIT)
		return (mlx_texture_to_image(mlx, exit_tex));
	if (type == EMPTY)
		return (mlx_texture_to_image(mlx, floor_tex));
	return (NULL);		
}