#include "so_long.h"

mlx_image_t *get_image(int type, mlx_t *mlx)
{
	mlx_texture_t* wall_tex;
	mlx_texture_t* floor_tex;
	mlx_texture_t* player_tex;
	mlx_texture_t* exit_tex;
	mlx_texture_t* collect_tex;

	wall_tex = mlx_load_png("assets/wall.png");
	floor_tex = mlx_load_png("assets/floor.png");
	player_tex = mlx_load_png("assets/player.png");
	exit_tex = mlx_load_png("assets/exit.png");
	collect_tex = mlx_load_png("assets/collectible.png");
	if (type == WALL)
		return (mlx_texture_to_image(mlx, wall_tex));
	if (type == PLAYER)
		return (mlx_texture_to_image(mlx, player_tex));
	if (type == COLLECTIBLE)
		return (mlx_texture_to_image(mlx, collect_tex));
	if (type == EXIT)
		return (mlx_texture_to_image(mlx, exit_tex));
	if (type == EMPTY)
		return (mlx_texture_to_image(mlx, floor_tex));
	return (NULL);		
}

void start_game(char *map)
{
	mlx_t *mlx;
	int width;
	int height;

	width = find(WIDTH, map) * TILE_SIZE;
	height = find(HEIGHT, map) * TILE_SIZE;
	if (!(mlx = mlx_init(width, height, "i love mitaniiiiiiiiiiiiiiiii", false)))
	{
		// puts();
		return ;
	}

    // Start the rendering loop
    mlx_loop(mlx);

    // Clean up when the window closes
    mlx_terminate(mlx);
    return ;
}


int main(int argc, char *argv[])
{
	// int argc = 2;
	// char *argv[2] = {"./so_long", "invalid19.ber"};
	char *map;

	if (argc != 2)
		return (printf("add good args"), -1);
	map = getmap(argv[1]);
	if (map == NULL)
		return (printf("invalid map name"), -1);
	
	print_map(map);

	if (!is_valid(map))
		return (free(map), printf("invalid map"), -1);
	
	printf("mapp good :)");
	
	start_game(map);

	free(map);
}
