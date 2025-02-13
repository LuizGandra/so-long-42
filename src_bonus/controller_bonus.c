/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:24:48 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 16:39:23 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_movement(t_mlx_data *data, char animation, int x, int y)
{
	if (!(data->map.grid[y][x] == EXIT_CELL)
		&& !(data->map.grid[y][x] == ENEMY_CELL))
	{
		if (data->map.grid[y][x] == WALL_CELL)
			return ;
		if (data->map.grid[y][x] == COLLECTIBLE_CELL)
			data->map.collectible_count--;
		data->map.grid[y][x] = PLAYER_CELL;
	}
	render_last_player_position(data);
	data->map.player_x = x;
	data->map.player_y = y;
	data->current_player_animation = animation;
	if (data->map.grid[y][x] == ENEMY_CELL)
		kill_player(data);
	data->player_movement_count++;
	print_movement_count(data);
	if (data->map.grid[y][x] == EXIT_CELL)
		check_exit(data);
}
