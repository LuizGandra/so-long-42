#include "so_long.h"

static int	is_a_wall(char *line);
static void	validate_line(t_map *map, char *line);
static void	has_valid_path(t_map *map);

void	read_map(t_mlx_data *data, char *map_path)
{
	int		map_fd;
	char	*line;
	char	*temp;

	temp = ft_strdup("");
	map_fd = open(map_path, O_RDONLY);
	if (!map_fd)
		throw_error("Invalid map file.\n");
	if (ft_strncmp(ft_strrchr(map_path, '.'), ".ber", 4))
		throw_error("Map file extension must be \".ber\".\n");
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break;
		data->map.height++;
		temp = ft_strjoin(temp, line);
		free(line);
	}
	data->map.grid = ft_split(temp, '\n');
	data->map.width = ft_strlen(data->map.grid[0]);
	free(temp);
	close(map_fd);
}

void	validate_map(t_map *map)
{
	int		i;
	char	**grid;

	i = 0;
	grid = map->grid;
	if (!is_a_wall(grid[i]) || !is_a_wall(grid[map->height - 1]))
		throw_error("Map must be closed by walls.\n");
	while (i < map->height)
		validate_line(map, grid[i++]);
	if (!map->exit_count)
		throw_error("Map must contain at least one exit.\n");
	if (!map->player_count)
		throw_error("Map must contain at least one start position.\n");
	if (!map->collectible_count)
		throw_error("Map must contain at least one collectible.\n");
	has_valid_path(map);
}

static void	validate_line(t_map *map, char *line)
{
	int	i;

	i = 0;
	if (map->width != ft_strlen(line))
		throw_error("Map must be rectangular.\n");
	if (line[i] != '1' || line[map->width - 1] != '1')
		throw_error("Map must be closed by walls.\n");
	while (i < map->width)
	{
		if (map->exit_count > 1)
			throw_error("Map must contain only one exit.\n");
		if (map->player_count > 1)
			throw_error("Map must contain only one start position.\n");
		if (line[i] == 'C')
			map->collectible_count++;
		else if (line[i] == 'E')
			map->exit_count++;
		else if (line[i] == 'P')
			map->player_count++;
		i++;
	}
}

static int is_a_wall(char *line)
{
	while (*line)
	{
		if (*line++ != '1')
			return (0);
	}
	return (1);
}

static void	has_valid_path(t_map *map)
{
	// TODO create the Flood Fill algorithm to check for valid paths
	// * I need to find: 1 E, 1 P, C = map->collectible_count
	// * If I dont find this, the map dont have a valid path!
	printf("Map has a valid path: %p\n", map);
}
