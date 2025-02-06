#include "so_long.h"

void	throw_error(char *msg)
{
	ft_printf(msg);
	exit(EXIT_FAILURE);
}

int	is_movement_valid(t_map *map, int x, int y)
{
	if (map->grid[y][x] == '1')
		return (0);
	return (1);
}