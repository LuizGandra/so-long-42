/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:17 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/10 18:19:29 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_player_on_exit(t_mlx_data *data, int x, int y)
{
	if (data->map.player_x == x && data->map.player_y == y)
		return (1);
	return (0);
}

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

void	print_movement_count(t_mlx_data *data)
{
	char	*str;
	char	*count_str;

	count_str = ft_itoa(data->player_movement_count);
	if (!count_str)
	{
		free(count_str);
		on_destroy(0, data);
	}
	str = ft_strjoin(MOVEMENT_LOG_STR, count_str);
	if (!str)
	{
		free(str);
		free(count_str);
		on_destroy(0, data);
	}
	render_movement_counter(data, str);
	free(count_str);
	free(str);
}
