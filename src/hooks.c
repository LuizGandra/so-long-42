/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:55 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/06 09:08:33 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_mlx_data *data)
{
	printf("Data: %p\n", data);
	if (keysym == XK_Up)
	{
		// TODO
		ft_printf("Keysym: %i\n", keysym);
	}
	else if (keysym == XK_Left)
	{
		// TODO
		ft_printf("Keysym: %i\n", keysym);
	}
	else if (keysym == XK_Down)
	{
		// TODO
		ft_printf("Keysym: %i\n", keysym);
	}
	else if (keysym == XK_Right)
	{
		// TODO
		ft_printf("Keysym: %i\n", keysym);
	}
	else if (keysym == XK_Escape)
	{
		ft_printf("Keysym: %i\n", keysym);
		on_destroy(keysym, data);
	}
	return (EXIT_SUCCESS);
}

int	on_destroy(int keysym, t_mlx_data *data)
{
	ft_printf("Keysym: %i\n", keysym);
	mlx_destroy_image(data->conn, data->images[BACKGROUND_INDEX]);
	ft_printf("\ndepois do destroy image\n");
	mlx_destroy_window(data->conn, data->window);
	ft_printf("\ndepois do destroy window\n");
	mlx_destroy_display(data->conn);
	ft_printf("\ndepois do destroy display\n");
	free(data->conn);
	exit(EXIT_SUCCESS);
}