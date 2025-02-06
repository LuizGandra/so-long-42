/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:24:48 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/06 18:59:57 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_exit(t_mlx_data *data);

void	handle_movement(t_mlx_data *data, int x, int y)
{
	if (data->map.grid[y][x] == '1')
		return ;
	if (!(data->map.grid[y][x] == 'E'))
	{
		if (data->map.grid[y][x] == 'C')
			data->map.collectible_count--;
		data->map.grid[y][x] = 'P';
	}
	else if (data->map.grid[y][x] == 'E')
		check_exit(data);
	if (data->map.grid[data->map.player_y][data->map.player_x] == 'E')
		mlx_put_image_to_window(data->conn, data->window,
			data->images[EXIT_INDEX], data->map.player_x * IMG_WIDTH,
			data->map.player_y * IMG_HEIGHT);
	else
	{
		data->map.grid[data->map.player_y][data->map.player_x] = '0';
		render_image(data, '0', data->map.player_x, data->map.player_y);
	}
	data->map.player_x = x;
	data->map.player_y = y;
	render_image(data, data->map.grid[y][x], x, y);
}

static void	check_exit(t_mlx_data *data)
{
	ft_printf("Chega aqui? %i\n", data->map.collectible_count);
	if (!data->map.collectible_count)
	{
		ft_printf("You win!\n");
		on_destroy(0, data);
	}
}
