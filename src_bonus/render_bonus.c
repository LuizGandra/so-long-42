/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:11:11 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/10 18:21:01 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	int	movement_log_bg_width;
	int	movement_log_bg_height;

	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	movement_log_bg_width = IMG_WIDTH / 2;
	movement_log_bg_height = IMG_HEIGHT / 2;
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
	data->images[ENEMY_INDEX] = mlx_xpm_file_to_image(data->conn, ENEMY_IMG,
			&width, &height);
	data->images[MOVEMENT_LOG_BG_INDEX] = mlx_xpm_file_to_image(data->conn,
			MOVEMENT_LOG_BG_IMG, &movement_log_bg_width,
			&movement_log_bg_height);
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
	else if (cell == ENEMY_CELL)
		image = data->images[ENEMY_INDEX];
	else
		return ;
	mlx_put_image_to_window(data->conn, data->window, image, x * IMG_WIDTH, y
		* IMG_HEIGHT);
}

void	render_last_player_position(t_mlx_data *data)
{
	if (data->map.grid[data->map.player_y][data->map.player_x] == EXIT_CELL)
		mlx_put_image_to_window(data->conn, data->window,
			data->images[EXIT_INDEX], data->map.player_x * IMG_WIDTH,
			data->map.player_y * IMG_HEIGHT);
	else
	{
		data->map.grid[data->map.player_y][data->map.player_x] = EMPTY_CELL;
		render_image(data, EMPTY_CELL, data->map.player_x, data->map.player_y);
	}
}

void	render_movement_counter(t_mlx_data *data, char *str)
{
	mlx_put_image_to_window(data->conn, data->window,
		data->images[MOVEMENT_LOG_BG_INDEX], MOVEMENT_LOG_X / 2, MOVEMENT_LOG_Y
		/ 2);
	mlx_string_put(data->conn, data->window, MOVEMENT_LOG_X, MOVEMENT_LOG_Y
		* 1.125, MOVEMENT_LOG_COLOR, str);
}
