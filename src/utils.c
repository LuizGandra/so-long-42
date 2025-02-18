/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:17 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 15:47:35 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_exit(t_mlx_data *data)
{
	if (!data->map.collectible_count)
	{
		ft_printf("\033[1;32m" "\n\nCONGRATULATIONS!\n" "\033[0m");
		ft_printf("\033[32m" "You won with %i movements.\n\n" "\033[0m",
			data->player_movement_count);
		on_destroy(0, data);
	}
}
