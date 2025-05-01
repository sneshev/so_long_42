#include "so_long.h"

void render_map(mlx_t *mlx, char **map)
{
    for (int y = 0; map[y]; y++)
    {
        for (int x = 0; map[y][x]; x++)
        {
            // Always draw floor first
            mlx_image_to_window(mlx, get_image(EMPTY, mlx), x * TILE_SIZE, y * TILE_SIZE);

            if (map[y][x] == '1')
                mlx_image_to_window(mlx, get_image(WALL, mlx), x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'P')
                mlx_image_to_window(mlx, get_image(PLAYER, mlx), x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'E')
                mlx_image_to_window(mlx, get_image(EXIT, mlx), x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'C')
                mlx_image_to_window(mlx, get_image(COLLECTIBLE, mlx), x * TILE_SIZE, y * TILE_SIZE);
        }
    }
}



void start_game(char *map_raw)
{
	mlx_t *mlx;
	t_game *game;
	t_player *player;

	printf("width: %d, height: %d\n", find(WIDTH, map_raw), find(HEIGHT, map_raw));
	if (!(mlx = mlx_init(find(WIDTH, map_raw) * TILE_SIZE, find(HEIGHT, map_raw) * TILE_SIZE, "i love mitaniiiiiiiiiiiiiiiii", false)))
	{
		// puts();
		return ;
	}

	game = setup_game(map_raw);
	if (!game)
		return ;
	player = setup_player(game->map, mlx);
	if (!player)
		return ;

	render_map(mlx, game->map);
	mlx_loop(mlx);

	cleanup(game, player, mlx);
	return ;
}