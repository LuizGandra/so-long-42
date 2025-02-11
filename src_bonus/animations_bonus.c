/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:37:53 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/11 10:25:30 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	run_player_animation(t_mlx_data *data)
{
	static t_animation player_animation;

	if (player_animation.delay == PLAYER_DELAY)
	{
		player_animation.delay = 0;
		if (player_animation.current_frame == 0)
			mlx_put_image_to_window(data->conn, data->window,
				data->sprites[PLAYER_INDEX], data->map.player_x * IMG_WIDTH,
				data->map.player_y * IMG_HEIGHT);
		else if (player_animation.current_frame == 1)
			mlx_put_image_to_window(data->conn, data->window,
				data->sprites[ENEMY_INDEX], data->map.player_x * IMG_WIDTH,
				data->map.player_y * IMG_HEIGHT);
		else if (player_animation.current_frame == 2)
			mlx_put_image_to_window(data->conn, data->window,
				data->sprites[WALL_INDEX], data->map.player_x * IMG_WIDTH,
				data->map.player_y * IMG_HEIGHT);
		else if (player_animation.current_frame == 3)
			mlx_put_image_to_window(data->conn, data->window,
				data->sprites[EXIT_INDEX], data->map.player_x * IMG_WIDTH,
				data->map.player_y * IMG_HEIGHT);
		player_animation.current_frame++;
		if (player_animation.current_frame == 4)
			player_animation.current_frame = 0;
	}
	else
		player_animation.delay++;
}