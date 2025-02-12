/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:24:48 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/12 14:37:43 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_movement(t_mlx_data *data, int x, int y)
{
	if (!(data->map.grid[y][x] == EXIT_CELL))
	{
		if (data->map.grid[y][x] == WALL_CELL)
			return ;
		if (data->map.grid[y][x] == COLLECTIBLE_CELL)
			data->map.collectible_count--;
		data->map.grid[y][x] = PLAYER_CELL;
	}
	if (data->map.grid[data->map.player_y][data->map.player_x] == EXIT_CELL)
		mlx_put_image_to_window(data->conn, data->window,
			data->images[EXIT_INDEX], data->map.player_x * IMG_WIDTH,
			data->map.player_y * IMG_HEIGHT);
	else
	{
		data->map.grid[data->map.player_y][data->map.player_x] = EMPTY_CELL;
		render_image(data, EMPTY_CELL, data->map.player_x, data->map.player_y);
	}
	data->map.player_x = x;
	data->map.player_y = y;
	render_image(data, data->map.grid[y][x], x, y);
	ft_printf(MOVEMENT_LOG, ++data->player_movement_count);
	if (data->map.grid[y][x] == EXIT_CELL)
		check_exit(data);
}
