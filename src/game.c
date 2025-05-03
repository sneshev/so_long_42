#include "so_long.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3


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


//  x is horizontal
void move(t_game *game, t_player *player, int new_y, int new_x)
{
    char **map;

    map = game->map;
    if (map[new_y][new_x] == WALL)
        return ;
    else if (map[new_y][new_x] == EXIT && player->points != game->points)
        return ;
    else if (map[new_y][new_x] == EXIT && player->points == game->points) // WIN GAME LESGO ... but only if all coins collected
    {
        if (player->points != game->points)
            return ;
        
        return ;
    }
    
    if (map[new_y][new_x] == COLLECTIBLE)
        player->points++;
    map[player->y][player->x] = '0';
    map[new_y][new_x] = 'P';
    mlx_image_to_window(game->mlx, get_image(EMPTY, game->mlx), player->x * TILE_SIZE, player->y * TILE_SIZE);
    mlx_image_to_window(game->mlx, get_image(PLAYER, game->mlx), new_x * TILE_SIZE, new_y * TILE_SIZE);
    player->moves++;
    printf("moves: %d\n", player->moves); //need to be ft_printf()!!!
    find_start(&player->y, &player->x, map);
}

// int mlx_key_hook(void *win, int (*funct_ptr)(int, void *), void *param);
void sethooks(mlx_key_data_t keydata, void *param)
{
    t_data *data;
    t_player *player;

    data = (t_data *)param;
    player = data->player;
    if (keydata.action != MLX_PRESS)
        return ;
    if (keydata.key == MLX_KEY_ESCAPE)
    {
        mlx_close_window(data->mlx);
        return ;
    }
    if (keydata.key == MLX_KEY_A) //left
        move(data->game, player, player->y, player->x - 1);
    if (keydata.key == MLX_KEY_D) //right
        move(data->game, player, player->y, player->x + 1);
    if (keydata.key == MLX_KEY_S) //down
        move(data->game, player, player->y + 1, player->x);
    if (keydata.key == MLX_KEY_W) //up
        move(data->game, player, player->y - 1, player->x);
}

void start_game(char *map_raw)
{
	mlx_t *mlx;
    t_data *data;
	t_game *game;
	t_player *player;

	if (!(mlx = mlx_init(find(WIDTH, map_raw) * TILE_SIZE, find(HEIGHT, map_raw) * TILE_SIZE, "i love mitaniiiiiiiiiiiiiiiii", false)))
	{
		// puts();
		return ;
	}

	game = setup_game(map_raw, mlx);
	if (!game)
		return ;
	player = setup_player(game->map, mlx);
	if (!player)
		return ;
    data = setup_data(game, player, mlx);
	if (!data) //still need to free prev.
		return ;

    // int input_window = mlx_new_window(mlx, 800, 600, "Key Hook Example");
    mlx_key_hook(mlx, &sethooks, data);

	render_map(mlx, game->map);
	mlx_loop(mlx);
	cleanup(data, game, player, mlx);
	return ;
}

