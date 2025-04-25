#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
    char    **tiles;  // 2D array of chars
    int     width;
    int     height;
}   t_map;

// Load map from file
bool load_map(const char *path, t_map *map);

// Free memory
void free_map(t_map *map);

int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif