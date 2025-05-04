/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:55:20 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/04 14:56:10 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/get_next_line.h"
#include "so_long.h"

char	*find_map(char *name)
{
	char	*dot;
	char	*temp;

	dot = ft_strrchr(name, '.');
	if (!dot || ft_strncmp(dot, ".ber", 5))
		return (NULL);
	temp = ft_strjoin("maps/", name);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*getmap(char *name)
{
	int		fd;
	char	*red;
	char	*map;

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
