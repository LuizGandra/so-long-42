/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:58:24 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 14:05:57 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_a_wall(char *line)
{
	while (*line)
	{
		if (*line++ != WALL_CELL)
			return (0);
	}
	return (1);
}

int	is_cell_valid(char cell)
{
	if (!ft_strchr(VALID_CELLS, cell))
		return (0);
	return (1);
}

void	update_player_data(t_map *map, int x, int y)
{
	map->player_count++;
	map->player_x = x;
	map->player_y = y;
}

void	update_enemy_data(t_map *map, int x, int y)
{
	int	i;

	i = map->enemies_count++;
	if (i < ENEMIES_COUNT)
	{
		map->enemies_data[i].x = x;
		map->enemies_data[i].y = y;
		map->enemies_data[i].current_animation = 'r';
		if (i == 0)
			map->enemies_data[i].color = 'r';
		else if (i == 1)
			map->enemies_data[i].color = 'b';
		else if (i == 2)
			map->enemies_data[i].color = 'p';
		else if (i == 3)
			map->enemies_data[i].color = 'y';
	}
}
