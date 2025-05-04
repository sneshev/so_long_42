#include "so_long.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

//  x is horizontal
void render_map(mlx_t *mlx, char **map)
{
    int x;
    int y;

    y = 0;
    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
            mlx_image_to_window(mlx, get_image(EMPTY, mlx), x * TILE_SIZE, y * TILE_SIZE);
            if (map[y][x] == '1')
                mlx_image_to_window(mlx, get_image(WALL, mlx), x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'P')
                mlx_image_to_window(mlx, get_image(PLAYER, mlx), x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'E')
                mlx_image_to_window(mlx, get_image(EXIT, mlx), x * TILE_SIZE, y * TILE_SIZE);
            else if (map[y][x] == 'C')
                mlx_image_to_window(mlx, get_image(COLLECTIBLE, mlx), x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
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
        write(1, "You win!\n", ft_strlen("You win!\n"));
        mlx_close_window(game->mlx);
        return ;
    }
    
    if (map[new_y][new_x] == COLLECTIBLE)
        player->points++;
    map[player->y][player->x] = '0';
    map[new_y][new_x] = 'P';
    mlx_image_to_window(game->mlx, get_image(EMPTY, game->mlx), player->x * TILE_SIZE, player->y * TILE_SIZE);
    mlx_image_to_window(game->mlx, get_image(PLAYER, game->mlx), new_x * TILE_SIZE, new_y * TILE_SIZE);
    player->moves++;
    ft_printf("moves: %d\n", player->moves); //need to be ft_printf()!!!
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
    if (keydata.key == MLX_KEY_A)
        move(data->game, player, player->y, player->x - 1);
    if (keydata.key == MLX_KEY_D)
        move(data->game, player, player->y, player->x + 1);
    if (keydata.key == MLX_KEY_S)
        move(data->game, player, player->y + 1, player->x);
    if (keydata.key == MLX_KEY_W)
        move(data->game, player, player->y - 1, player->x);
}

int so_long(char *map_raw)
{
	mlx_t *mlx;
    t_data *data;
	t_game *game;
	t_player *player;

	if (!(mlx = mlx_init(find(WIDTH, map_raw) * TILE_SIZE, find(HEIGHT, map_raw) * TILE_SIZE, "so_long", true)))
    {
        write(2, "Failed to initialize MLX", ft_strlen("Failed to initialize MLX"));
        return (-1);
    }
	game = setup_game(map_raw, mlx);
	if (!game)
		return (-1);
	player = setup_player(game->map, mlx);
	if (!player)
        return (cleanup(NULL, game, NULL, mlx), -1);
    data = setup_data(game, player, mlx);
	if (!data)
		return (cleanup(NULL, NULL, player, mlx), -1);
    mlx_key_hook(mlx, &sethooks, data);
	render_map(mlx, game->map);
	mlx_loop(mlx);
    cleanup(data, game, player, mlx);
    return (1);
}

