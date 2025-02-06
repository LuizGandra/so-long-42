/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:55 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/06 17:29:26 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Up)
		handle_movement(data, data->map.player_x, data->map.player_y - 1);
	else if (keysym == XK_Left)
		handle_movement(data, data->map.player_x - 1, data->map.player_y);
	else if (keysym == XK_Down)
		handle_movement(data, data->map.player_x, data->map.player_y + 1);
	else if (keysym == XK_Right)
		handle_movement(data, data->map.player_x + 1, data->map.player_y);
	else if (keysym == XK_Escape)
		on_destroy(keysym, data);
	return (EXIT_SUCCESS);
}

int	on_destroy(int keysym, t_mlx_data *data)
{
	ft_printf("Keysym: %i\n", keysym);
	mlx_destroy_image(data->conn, data->images[BACKGROUND_INDEX]);
	mlx_destroy_window(data->conn, data->window);
	mlx_destroy_display(data->conn);
	free(data->conn);
	exit(EXIT_SUCCESS);
}
