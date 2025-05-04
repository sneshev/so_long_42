/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:23:31 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/04 14:26:39 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*setup_data(t_game *game, t_player *player, mlx_t *mlx)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->game = game;
	data->player = player;
	data->mlx = mlx;
	return (data);
}

t_game	*setup_game(char *map_raw, mlx_t *mlx)
{
	t_game	*game;

	game = (t_game *)malloc(1 * sizeof(t_game));
	if (!game)
	{
		return (NULL);
	}
	game->map = ft_split(map_raw, '\n');
	if (game->map == NULL)
	{
		return (free(game), NULL);
	}
	game->width = find(WIDTH, map_raw);
	game->height = find(HEIGHT, map_raw);
	game->points = count(map_raw, 'C');
	game->mlx = mlx;
	game->emptyimg = get_image(EMPTY, mlx);
	if (!game->emptyimg)
	{
		free_arr(game->map);
		free(game);
		return (NULL);
	}
	return (game);
}

t_player	*setup_player(char **map, mlx_t *mlx)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->points = 0;
	player->moves = 0;
	find_start(&player->y, &player->x, map);
	player->img = get_image(PLAYER, mlx);
	if (!player->img)
		return (free(player), NULL);
	return (player);
}
