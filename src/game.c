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
int move(t_game *game, t_player *player, int new_y, int new_x)
{
    char **map;

    map = game->map;
    if (map[new_y][new_x] == WALL)
        return -99999;
    else if (map[new_y][new_x] == EXIT && player->points == game->points)
    {
        //WIN GAME LESGO ... but only if all coins collected
        return 999999;
    }
    
    if (map[new_y][new_x] == COLLECTIBLE)
        player->points++;
    map[player->y][player->x] = '0';
    map[new_y][new_x] = 'P';
    find_start(&player->y, &player->x, map);
    player->moves++;
    render_map(map);

}

int mlx_key_hook(void *win, int (*funct_ptr)(int, void *), void *param);
int sethooks(int code, void *param)
{
    t_data *data;

    data = (t_data *)param;
    if (code == 53)
    {
        mlx_loop_end(data->mlx);
    }
    if (code == 123 || code == 0) //left
    {
        move(data->game, data->player, player->y, player->x - 1);
    }
    if (code == 124 || code == 2) //right
    {
        move(data->game, data->player, player->y, player->x + 1);

    }
    if (code == 125 || code == 1) //down
    {
        move(data->game, data->player, player->y - 1, player->x);

    }
    if (code == 126 || code == 13) //up
    {
        move(data->game, data->player, player->y + 1, player->x);

    }

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

	game = setup_game(map_raw);
	if (!game)
		return ;
	player = setup_player(game->map, mlx);
	if (!player)
		return ;
    data = setup_data(game, player, mlx);
	if (!data) //still need to free prev.
		return ;

    void *input_window = mlx_new_window(mlx, 800, 600, "Key Hook Example");
    mlx_key_hook(input_window, sethooks, data);

	render_map(mlx, game->map);
	mlx_loop(mlx);

	cleanup(game, player, mlx);
	return ;
}