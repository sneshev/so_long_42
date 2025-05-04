/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:56:55 by sneshev           #+#    #+#             */
/*   Updated: 2025/05/04 14:57:30 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	*map;

	if (argc != 2)
		return (write(1, "Error\n", 6), -1);
	map = getmap(argv[1]);
	if (map == NULL)
		return (write(1, "Error\n", 6), -1);
	if (!is_valid(map))
		return (free(map), write(1, "Error\n", 6), -1);
	so_long(map);
	free(map);
}
