#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 0
# define HEIGHT 1
# define TILE_SIZE 32

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define REACHED 'X'

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../utils/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"



typedef struct s_game
{
    mlx_image_t *emptyimg;
    mlx_t       *mlx;
    char        **map;
    int         width;
    int         height;
    int         points;
}   t_game;

typedef struct s_player
{
    mlx_image_t *img;
    int         points;
    int         moves;
    int         x;
    int         y;

}   t_player;


typedef struct s_data
{
    t_game *game;
    t_player *player;
    mlx_t *mlx;
}   t_data;

//helpers
void        print_map(char *map);
void        print_map2(char **map);


//utils
void        free_arr(char **arr);
void        cleanup(t_data *data, t_game *game, t_player *player, mlx_t *mlx);
int         find(int attrib, char *map);
int         count(char *map, char c);

mlx_image_t *get_image(int type, mlx_t *mlx);


//map
char        *getmap(char *name);
bool        is_valid(char *map);
bool        is_playable(char **map);
void        find_start(int *start_x, int *start_y, char **map);

//game
int         so_long(char *map_raw);
t_data      *setup_data(t_game *game, t_player *player, mlx_t *mlx);
t_game      *setup_game(char *map_raw, mlx_t *mlx);
t_player    *setup_player(char **map, mlx_t *mlx);



#endif