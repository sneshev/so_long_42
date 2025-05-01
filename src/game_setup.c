#include "so_long.h"
#include <stdlib.h>  // for malloc()

t_game *setup_game(char *map_raw)
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
        return (NULL);
    }
	game->width = find(WIDTH, map_raw);
	game->height= find(HEIGHT, map_raw);
	game->points = count(map_raw, 'C');
    return (game);
}

t_player *setup_player(char **map, mlx_t *mlx)
{
	t_player    *player;

    player = (t_player *)malloc(sizeof(t_player));
    if (!player)
        return (NULL);
    player->points = 0;
    find_start(&player->x, &player->y, map);
    player->img = get_image(PLAYER, mlx);
    return (player);
}
