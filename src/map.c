/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:08:26 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/06 09:08:43 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_a_wall(char *line);
static void	validate_line(t_map *map, char *line, int height);
static void	has_valid_path(t_map *map, int x, int y);

void	read_map(t_mlx_data *data, char *map_path)
{
	int		map_fd;
	char	*line;
	char	*temp;

	temp = ft_strdup("");
	map_fd = open(map_path, O_RDONLY);
	if (!map_fd)
		throw_error("Invalid map file.\n");
	if (ft_strcmp(ft_strrchr(map_path, '.'), ".ber"))
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
	data->validation_map.grid = ft_split(temp, '\n');
	data->map.width = ft_strlen(data->map.grid[0]);
	data->validation_map.width = ft_strlen(data->map.grid[0]);
	free(temp);
	close(map_fd);
}

void	validate_map(t_map *map, t_map *validation_map)
{
	int		i;
	char	**grid;

	i = 0;
	grid = map->grid;
	if (!is_a_wall(grid[i]) || !is_a_wall(grid[map->height - 1]))
		throw_error("Map must be closed by walls.\n");
	while (i < map->height)
	{
		validate_line(map, grid[i], i);
		i++;
	}
	if (!map->exit_count)
		throw_error("Map must contain at least one exit.\n");
	if (!map->player_count)
		throw_error("Map must contain at least one start position.\n");
	if (!map->collectible_count)
		throw_error("Map must contain at least one collectible.\n");
	has_valid_path(validation_map, map->player_x, map->player_y);
	if (validation_map->exit_count != 1 ||
			validation_map->collectible_count != map->collectible_count)
		throw_error("The map must contain a valid path.\n");
}

static void	validate_line(t_map *map, char *line, int height)
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
		{
			map->player_count++;
			map->player_x = i;
			map->player_y = height;
		}
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

// * Flood Fill Algorithm
static void	has_valid_path(t_map *map, int x, int y)
{
	if (map->grid[y][x] == '1' || map->grid[y][x] == 'X')
		return;
	if (map->grid[y][x] == 'C')
		map->collectible_count++;
	else if (map->grid[y][x] == 'E')
		map->exit_count++;
	map->grid[y][x] = 'X';
	has_valid_path(map, x + 1, y);
	has_valid_path(map, x - 1, y);
	has_valid_path(map, x, y + 1);
	has_valid_path(map, x, y - 1);
}
