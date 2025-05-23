/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:19:40 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/16 20:45:09 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	cleanup(t_data *data, t_game *game, t_player *player, mlx_t *mlx)
{
	if (data)
		free(data);
	if (game)
	{
		if (game->map)
			free_arr(game->map);
		if (game->emptyimg)
			mlx_delete_image(mlx, game->emptyimg);
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

int	find(int attrib, char *map)
{
	int	count;

	count = 1;
	if (attrib == WIDTH)
	{
		while (map[count] && map[count] != '\n')
			count++;
		return (count);
	}
	else if (attrib == HEIGHT)
	{
		while (*(map++))
		{
			if (*map == '\n' && *(map + 1) && *(map + 1) != '\n')
				count++;
		}
		return (count);
	}
	else
		return (0);
	return (1);
}

int	count(char *map, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}

mlx_image_t	*get_image2(int type, mlx_t *mlx)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = NULL;
	if (type == WALL)
		tex = mlx_load_png("images/rock.png");
	else if (type == PLAYER)
		tex = mlx_load_png("images/spirit.png");
	else if (type == COLLECTIBLE)
		tex = mlx_load_png("images/skull.png");
	else if (type == EXIT)
		tex = mlx_load_png("images/portal.png");
	else if (type == EMPTY)
		tex = mlx_load_png("images/grass.png");
	if (!tex)
	{
		ft_printf("Failed to load texture for type %d\n", type);
		return (NULL);
	}
	img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	return (img);
}

mlx_image_t	*get_image(int type, mlx_t *mlx)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	// if (type == WALL)
		// tex = mlx_load_png("images/BLACK.png");
	if (type == COLLECTIBLE)
		tex = mlx_load_png("images/collectable.png");
	// else if (type == EMPTY)
	// 	tex = mlx_load_png("images/WHITE.png");
	else 
		tex = mlx_load_png("images/Mitani.png");

	img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	return (img);
}

