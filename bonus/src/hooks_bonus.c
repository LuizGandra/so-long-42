/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:55 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 15:31:27 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	on_keypress(int keysym, t_mlx_data *data)
{
	if (!data->current_player_animation && !data->game_over)
	{
		if (keysym == XK_Up || keysym == XK_w)
			handle_movement(data, UP_ID, data->map.player_x, data->map.player_y
				- 1);
		else if (keysym == XK_Left || keysym == XK_a)
			handle_movement(data, LEFT_ID, data->map.player_x - 1,
				data->map.player_y);
		else if (keysym == XK_Down || keysym == XK_s)
			handle_movement(data, DOWN_ID, data->map.player_x,
				data->map.player_y + 1);
		else if (keysym == XK_Right || keysym == XK_d)
			handle_movement(data, RIGHT_ID, data->map.player_x + 1,
				data->map.player_y);
	}
	if (keysym == XK_Escape)
		on_destroy(keysym, data);
	return (EXIT_SUCCESS);
}

int	on_loop(t_mlx_data *data)
{
	int	i;

	i = 0;
	if (data->current_player_animation)
		run_player_animation(data);
	else if (data->game_over)
		game_over(data);
	while (i < data->map.enemies_count)
	{
		if (!(data->map.enemies_data[i].x === data->map.player_x
			&& data->map.enemies_data[i].y === data->map.player_y))
			run_enemy_animation(data, &data->map.enemies_data[i], i);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	on_destroy(int keysym, t_mlx_data *data)
{
	data = get_data();
	(void)keysym;
	clean_grid(data->map.grid);
	clean_grid(data->flooded_map.grid);
	clean_player_sprites(data, NULL);
	clean_enemies_sprites(data, NULL);
	mlx_destroy_image(data->conn, data->static_sprites[BACKGROUND_INDEX]);
	mlx_destroy_image(data->conn, data->static_sprites[WALL_INDEX]);
	mlx_destroy_image(data->conn, data->static_sprites[COLLECTIBLE_INDEX]);
	mlx_destroy_image(data->conn, data->static_sprites[EXIT_INDEX]);
	mlx_destroy_image(data->conn, data->static_sprites[MOVEMENT_LOG_BG_INDEX]);
	mlx_destroy_window(data->conn, data->window);
	mlx_destroy_display(data->conn);
	free(data->conn);
	exit(EXIT_SUCCESS);
}
