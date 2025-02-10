/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:55 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/10 14:20:16 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	on_keypress(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Up || keysym == XK_w)
		handle_movement(data, data->map.player_x, data->map.player_y - 1);
	else if (keysym == XK_Left || keysym == XK_a)
		handle_movement(data, data->map.player_x - 1, data->map.player_y);
	else if (keysym == XK_Down || keysym == XK_s)
		handle_movement(data, data->map.player_x, data->map.player_y + 1);
	else if (keysym == XK_Right || keysym == XK_d)
		handle_movement(data, data->map.player_x + 1, data->map.player_y);
	else if (keysym == XK_Escape)
		on_destroy(keysym, data);
	return (EXIT_SUCCESS);
}

int	on_destroy(int keysym, t_mlx_data *data)
{
	data = get_data();
	(void)keysym;
	clean_grid(data->map.grid);
	clean_grid(data->validation_map.grid);
	mlx_destroy_image(data->conn, data->images[BACKGROUND_INDEX]);
	mlx_destroy_image(data->conn, data->images[WALL_INDEX]);
	mlx_destroy_image(data->conn, data->images[COLLECTIBLE_INDEX]);
	mlx_destroy_image(data->conn, data->images[EXIT_INDEX]);
	mlx_destroy_image(data->conn, data->images[PLAYER_INDEX]);
	mlx_destroy_window(data->conn, data->window);
	mlx_destroy_display(data->conn);
	free(data->conn);
	exit(EXIT_SUCCESS);
}
