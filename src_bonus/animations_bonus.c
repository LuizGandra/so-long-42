/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:37:53 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/10 18:51:01 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// TODO reduce the animation fps (this is possible?)
// ? if I cant reduce the animation fps, I can animate just the death / walk
// TODO add sprites for the animation and for each direction
void	run_player_animation(t_mlx_data *data)
{
	static int frame = 0;

	if (frame == 0)
		mlx_put_image_to_window(data->conn, data->window,
			data->images[PLAYER_INDEX], data->map.player_x * IMG_WIDTH,
			data->map.player_y * IMG_HEIGHT);
	else if (frame == 1)
		mlx_put_image_to_window(data->conn, data->window,
			data->images[ENEMY_INDEX], data->map.player_x * IMG_WIDTH,
			data->map.player_y * IMG_HEIGHT);
	else if (frame == 2)
		mlx_put_image_to_window(data->conn, data->window,
			data->images[WALL_INDEX], data->map.player_x * IMG_WIDTH,
			data->map.player_y * IMG_HEIGHT);
	else if (frame == 3)
		mlx_put_image_to_window(data->conn, data->window,
			data->images[EXIT_INDEX], data->map.player_x * IMG_WIDTH,
			data->map.player_y * IMG_HEIGHT);
	frame++;
	if (frame == 4)
		frame = 0;
}