/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_marrp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:23:11 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/04 14:18:45 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_start(int *start_y, int *start_x, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == PLAYER)
			{
				*start_x = x;
				*start_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(int x, int y, char **map)
{
	if (!map[x][y] || x < 0 || y < 0 || map[x][y] == REACHED)
		return ;
	if (map[x][y] == PLAYER || map[x][y] == EXIT
	|| map[x][y] == EMPTY || map[x][y] == COLLECTIBLE)
		map[x][y] = REACHED;
	if (map[x][y] == REACHED)
	{
		flood_fill(x + 1, y, map);
		flood_fill(x - 1, y, map);
		flood_fill(x, y + 1, map);
		flood_fill(x, y - 1, map);
	}
}

bool	check_for_stuck(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y] && map[x][y] != '\n')
		{
			if (map[x][y] != '1' && map[x][y] != 'X')
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

//validate walking area, exit, and collectables access
bool	is_playable(char **map)
{
	int	start_x;
	int	start_y;

	find_start(&start_x, &start_y, map);
	flood_fill(start_x, start_y, map);
	if (check_for_stuck(map))
		return (false);
	return (true);
}
