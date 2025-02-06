/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:13:01 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/06 15:30:10 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	static t_mlx_data	data;

	if (argc != 2)
		throw_error("Invalid number of arguments.\n"
			"Usage: ./so_long <map_path>.ber\n");
	read_map(&data, argv[1]);
	validate_map(&data.map, &data.validation_map);
	data.conn = mlx_init();
	if (!data.conn)
		return (EXIT_FAILURE);
	data.window = mlx_new_window(data.conn, data.map.width * IMG_WIDTH,
			data.map.height * IMG_HEIGHT, "So Long");
	if (!data.window)
		return (free(data.conn), EXIT_FAILURE);
	render_map(&data);
	mlx_hook(data.window, KeyRelease, KeyReleaseMask, on_keypress, &data);
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, on_destroy,
		&data);
	mlx_loop(data.conn);
	return (EXIT_SUCCESS);
}
