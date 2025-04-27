#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
    char    **tiles;  // 2D array of chars
    int     width;
    int     height;
}   t_map;



//helpers
void print_map(char **map);



#endif