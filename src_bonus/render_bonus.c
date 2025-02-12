/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:11:11 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/12 18:46:43 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_image(t_mlx_data *data, char cell, int x, int y);

void	render_map(t_mlx_data *data)
{
	char	**grid;
	int		x;
	int		y;

	load_all_assets(data);
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

void	render_image(t_mlx_data *data, char cell, int x, int y)
{
	int		is_player_on_exit;
	void	*image;

	is_player_on_exit = check_player_on_exit(data, x, y);
	if (cell == EMPTY_CELL)
		image = data->static_sprites[BACKGROUND_INDEX];
	else if (cell == WALL_CELL)
		image = data->static_sprites[WALL_INDEX];
	else if (cell == COLLECTIBLE_CELL)
		image = data->static_sprites[COLLECTIBLE_INDEX];
	else if (cell == EXIT_CELL && !is_player_on_exit)
		image = data->static_sprites[EXIT_INDEX];
	else if (cell == PLAYER_CELL || is_player_on_exit)
		image = data->player_animations[DEFAULT_SPRITE_INDEX].sprites[DEFAULT_SPRITE_INDEX];
	else if (cell == ENEMY_CELL)
		image = data->enemies_animations[DEFAULT_SPRITE_INDEX][DEFAULT_SPRITE_INDEX].sprites[DEFAULT_SPRITE_INDEX];
	else
		return ;
	mlx_put_image_to_window(data->conn, data->window, image, x * IMG_WIDTH, y
		* IMG_HEIGHT);
}

void	render_animation_frame(t_mlx_data *data, void *frame, int x, int y)
{
	mlx_put_image_to_window(data->conn, data->window, frame, x * IMG_WIDTH, y
		* IMG_HEIGHT);
}

void	render_last_player_position(t_mlx_data *data)
{
	if (data->map.grid[data->map.player_y][data->map.player_x] == EXIT_CELL)
		mlx_put_image_to_window(data->conn, data->window,
			data->static_sprites[EXIT_INDEX], data->map.player_x * IMG_WIDTH,
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
		data->static_sprites[MOVEMENT_LOG_BG_INDEX], MOVEMENT_LOG_X / 2,
		MOVEMENT_LOG_Y / 2);
	mlx_string_put(data->conn, data->window, MOVEMENT_LOG_X, MOVEMENT_LOG_Y
		* 1.125, MOVEMENT_LOG_COLOR, str);
}
