/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:13:01 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/05 19:56:24 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_XPM_images(t_mlx_data *data);

int	main(int argc, char *argv[])
{
	static t_mlx_data	data;

	if (argc != 2)
		throw_error("Invalid number of arguments.\nUsage: ./so_long <map_path>.ber\n");
	// * read and validate map
	read_map(&data, argv[1]);
	validate_map(&data.map);
	// * init MLX connection
	data.conn = mlx_init();
	if (!data.conn)
		return (EXIT_FAILURE);
	data.window = mlx_new_window(data.conn, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");
	if (!data.window)
		return (free(data.conn), EXIT_FAILURE);
	// * load all XPM files into MLX
	load_XPM_images(&data);
	// * render background on window
	mlx_put_image_to_window(data.conn, data.window, data.images[BACKGROUND_INDEX], 0, 0);
	// * defines a hook for the KeyRelease event
	mlx_hook(data.window, KeyRelease, KeyReleaseMask, on_keypress, &data);
	// * defines a hook for the DestroyNotify event
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, on_destroy, &data);
	// * loops over the pointer, triggering each hook in order of registration
	mlx_loop(data.conn);
	return (EXIT_SUCCESS);
}

static void	load_XPM_images(t_mlx_data *data)
{
	int	WIDTH = IMG_WIDTH;
	int	HEIGHT = IMG_HEIGHT;

	data->images[BACKGROUND_INDEX] = mlx_xpm_file_to_image(data->conn, BACKGROUND_IMG, &WIDTH, &HEIGHT);
	data->images[WALL_INDEX] = mlx_xpm_file_to_image(data->conn, WALL_IMG, &WIDTH, &HEIGHT);
	data->images[COLLECTIBLE_INDEX] = mlx_xpm_file_to_image(data->conn, COLLECTIBLE_IMG, &WIDTH, &HEIGHT);
	data->images[EXIT_INDEX] = mlx_xpm_file_to_image(data->conn, EXIT_IMG, &WIDTH, &HEIGHT);
	data->images[PLAYER_INDEX] = mlx_xpm_file_to_image(data->conn, PLAYER_IMG, &WIDTH, &HEIGHT);
}
