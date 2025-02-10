/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:13:01 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/10 18:05:15 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx_data	*data;

	data = get_data();
	if (argc != 2)
		throw_error("Invalid number of arguments.\n"
			"Usage: ./so_long <map_path>.ber\n");
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber"))
		throw_error("The map file extension must be \".ber\".\n");
	read_map(data, argv[1]);
	validate_map(data, &data->map, &data->flooded_map);
	data->conn = mlx_init();
	if (!data->conn)
		clean_exit(data, "Error starting MLX. Please try again!\n");
	ft_printf(MOVEMENT_LOG, data->player_movement_count);
	data->window = mlx_new_window(data->conn, data->map.width * IMG_WIDTH,
			data->map.height * IMG_HEIGHT, "So Long");
	if (!data->window)
		clean_exit(data, "Error starting MLX. Please try again!\n");
	render_map(data);
	mlx_hook(data->window, KeyPress, KeyPressMask, on_keypress, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, on_destroy,
		data);
	mlx_loop(data->conn);
	return (EXIT_SUCCESS);
}
