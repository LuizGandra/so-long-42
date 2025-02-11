/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:11:11 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/11 15:13:46 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_xpm_images(t_mlx_data *data);
void		render_image(t_mlx_data *data, char cell, int x, int y);

void	render_map(t_mlx_data *data)
{
	char	**grid;
	int		x;
	int		y;

	load_xpm_images(data);
	grid = data->map.grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			render_image(data, grid[y][x], x, y);
			x++;
		}
		y++;
	}
}

static void	load_xpm_images(t_mlx_data *data)
{
	int	width;
	int	height;

	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	data->images[BACKGROUND_INDEX] = mlx_xpm_file_to_image(data->conn,
			BACKGROUND_IMG, &width, &height);
	data->images[WALL_INDEX] = mlx_xpm_file_to_image(data->conn, WALL_IMG,
			&width, &height);
	data->images[COLLECTIBLE_INDEX] = mlx_xpm_file_to_image(data->conn,
			COLLECTIBLE_IMG, &width, &height);
	data->images[EXIT_INDEX] = mlx_xpm_file_to_image(data->conn, EXIT_IMG,
			&width, &height);
	data->images[PLAYER_INDEX] = mlx_xpm_file_to_image(data->conn, PLAYER_IMG,
			&width, &height);
}

void	render_image(t_mlx_data *data, char cell, int x, int y)
{
	int		is_player_on_exit;
	void	*image;

	is_player_on_exit = check_player_on_exit(data, x, y);
	if (cell == EMPTY_CELL)
		image = data->images[BACKGROUND_INDEX];
	else if (cell == WALL_CELL)
		image = data->images[WALL_INDEX];
	else if (cell == COLLECTIBLE_CELL)
		image = data->images[COLLECTIBLE_INDEX];
	else if (cell == EXIT_CELL && !is_player_on_exit)
		image = data->images[EXIT_INDEX];
	else if (cell == PLAYER_CELL || is_player_on_exit)
		image = data->images[PLAYER_INDEX];
	else
		return ;
	mlx_put_image_to_window(data->conn, data->window, image, x * IMG_WIDTH, y
		* IMG_HEIGHT);
}
