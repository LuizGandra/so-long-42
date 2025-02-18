/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:08:26 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 17:21:07 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_line(t_mlx_data *data, t_map *map, char *line, int height);
static void	has_valid_path(t_map *map, int x, int y);

void	read_map(t_mlx_data *data, char *map_path)
{
	int		map_fd;
	char	*line;
	char	*temp;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		throw_error("The map file was not found.\n");
	line = get_next_line(map_fd);
	if (!line)
		clean_exit_fd(map_fd, "The map file is empty.\n");
	temp = ft_strdup("");
	while (line)
	{
		data->map.height++;
		temp = ft_strjoin_free(temp, line);
		free(line);
		line = get_next_line(map_fd);
	}
	data->map.grid = ft_split(temp, '\n');
	data->flooded_map.grid = ft_split(temp, '\n');
	data->map.width = ft_strlen(data->map.grid[0]);
	free(temp);
	close(map_fd);
}

void	validate_map(t_mlx_data *data, t_map *map, t_map *flooded_map)
{
	int		i;
	char	**grid;

	i = 0;
	grid = map->grid;
	if (map->width * IMG_WIDTH > MAX_SCREEN_WIDTH || map->height
		* IMG_HEIGHT > MAX_SCREEN_HEIGHT)
		clean_exit(data, "The map size must be less than or equal to 30x17.\n");
	if (!is_a_wall(grid[i]) || !is_a_wall(grid[map->height - 1]))
		clean_exit(data, "The map must be closed by walls.\n");
	while (i < map->height)
	{
		validate_line(data, map, grid[i], i);
		i++;
	}
	if (!map->exit_count || map->exit_count > 1)
		clean_exit(data, "The map must contain one exit.\n");
	if (!map->player_count || map->player_count > 1)
		clean_exit(data, "The map must contain one start position.\n");
	if (!map->collectible_count)
		clean_exit(data, "The map must contain at least one collectible.\n");
	has_valid_path(flooded_map, map->player_x, map->player_y);
	if (flooded_map->exit_count != 1
		|| flooded_map->collectible_count != map->collectible_count)
		clean_exit(data, "The map must contain a valid path.\n");
}

static void	validate_line(t_mlx_data *data, t_map *map, char *line, int height)
{
	int	i;

	i = 0;
	if (map->width != ft_strlen(line))
		clean_exit(data, "The map must be rectangular.\n");
	if (line[i] != WALL_CELL || line[map->width - 1] != WALL_CELL)
		clean_exit(data, "The map must be closed by walls.\n");
	while (i < map->width)
	{
		if (!is_cell_valid(line[i]))
			clean_exit(data,
						"The map can only contain the characters "
						"0, 1, C, E and P.\n");
		if (line[i] == COLLECTIBLE_CELL)
			map->collectible_count++;
		else if (line[i] == EXIT_CELL)
			map->exit_count++;
		else if (line[i] == PLAYER_CELL)
		{
			map->player_count++;
			map->player_x = i;
			map->player_y = height;
		}
		i++;
	}
}

// * Flood Fill Algorithm
static void	has_valid_path(t_map *map, int x, int y)
{
	if (map->grid[y][x] == WALL_CELL || map->grid[y][x] == WALKED_CELL)
		return ;
	if (map->grid[y][x] == COLLECTIBLE_CELL)
		map->collectible_count++;
	else if (map->grid[y][x] == EXIT_CELL)
		map->exit_count++;
	map->grid[y][x] = WALKED_CELL;
	has_valid_path(map, x + 1, y);
	has_valid_path(map, x - 1, y);
	has_valid_path(map, x, y + 1);
	has_valid_path(map, x, y - 1);
}
