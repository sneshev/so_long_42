#include "so_long.h"

int main()
{
	int argc = 2;
	char *argv[2] = {"./so_long", "test.ber"};
	char *map;

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
