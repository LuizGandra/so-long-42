/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:30:39 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/11 12:21:47 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_sprite(t_mlx_data *data, char cell, int index, char *path)
{
	int	width;
	int	height;

	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	if (cell == PLAYER_CELL)
		data->player_sprites[index] = mlx_xpm_file_to_image(data->conn,
			path, &width, &height);
	else if (cell == ENEMY_CELL)
		data->enemy_sprites[index] = mlx_xpm_file_to_image(data->conn,
			path, &width, &height);
	else if (cell == COLLECTIBLE_CELL)
		data->static_sprites[index] = mlx_xpm_file_to_image(data->conn,
			path, &width, &height);
	else if (cell == EXIT_CELL)
		data->static_sprites[index] = mlx_xpm_file_to_image(data->conn,
			path, &width, &height);
	else if (cell == WALL_CELL)
		data->static_sprites[index] = mlx_xpm_file_to_image(data->conn,
			path, &width, &height);
	else
		data->static_sprites[index] = mlx_xpm_file_to_image(data->conn,
			path, &width, &height);
}

void	load_static_sprites(t_mlx_data *data)
{
	load_sprite(data, WALL_CELL, WALL_INDEX, WALL_IMG);
	load_sprite(data, COLLECTIBLE_CELL, COLLECTIBLE_INDEX, COLLECTIBLE_IMG);
	load_sprite(data, EXIT_CELL, EXIT_INDEX, EXIT_IMG);
	load_sprite(data, 0, MOVEMENT_LOG_BG_INDEX, MOVEMENT_LOG_BG_IMG);
}

void	load_player_sprites(t_mlx_data *data)
{
	load_sprite(data, PLAYER_CELL, PLAYER_R_01_INDEX, PLAYER_R_01_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_R_02_INDEX, PLAYER_R_02_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_R_03_INDEX, PLAYER_R_03_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_R_04_INDEX, PLAYER_R_04_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_L_01_INDEX, PLAYER_L_01_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_L_02_INDEX, PLAYER_L_02_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_L_03_INDEX, PLAYER_L_03_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_L_04_INDEX, PLAYER_L_04_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_U_01_INDEX, PLAYER_U_01_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_U_02_INDEX, PLAYER_U_02_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_U_03_INDEX, PLAYER_U_03_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_U_04_INDEX, PLAYER_U_04_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_D_01_INDEX, PLAYER_D_01_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_D_02_INDEX, PLAYER_D_02_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_D_03_INDEX, PLAYER_D_03_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_D_04_INDEX, PLAYER_D_04_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_DEATH_01_INDEX, PLAYER_DEATH_01_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_DEATH_02_INDEX, PLAYER_DEATH_02_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_DEATH_03_INDEX, PLAYER_DEATH_03_IMG);
	load_sprite(data, PLAYER_CELL, PLAYER_DEATH_04_INDEX, PLAYER_DEATH_04_IMG);
}

void	load_red_and_blue_enemy_sprites(t_mlx_data *data)
{
	load_sprite(data, ENEMY_CELL, ENEMY_RED_R_01_INDEX, ENEMY_RED_R_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_RED_R_02_INDEX, ENEMY_RED_R_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_RED_L_01_INDEX, ENEMY_RED_L_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_RED_L_02_INDEX, ENEMY_RED_L_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_RED_U_01_INDEX, ENEMY_RED_U_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_RED_U_02_INDEX, ENEMY_RED_U_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_RED_D_01_INDEX, ENEMY_RED_D_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_RED_D_02_INDEX, ENEMY_RED_D_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_BLUE_R_01_INDEX, ENEMY_BLUE_R_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_BLUE_R_02_INDEX, ENEMY_BLUE_R_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_BLUE_L_01_INDEX, ENEMY_BLUE_L_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_BLUE_L_02_INDEX, ENEMY_BLUE_L_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_BLUE_U_01_INDEX, ENEMY_BLUE_U_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_BLUE_U_02_INDEX, ENEMY_BLUE_U_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_BLUE_D_01_INDEX, ENEMY_BLUE_D_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_BLUE_D_02_INDEX, ENEMY_BLUE_D_02_IMG);
}

void	load_pink_and_yellow_enemy_sprites(t_mlx_data *data)
{
	load_sprite(data, ENEMY_CELL, ENEMY_PINK_R_01_INDEX, ENEMY_PINK_R_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_PINK_R_02_INDEX, ENEMY_PINK_R_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_PINK_L_01_INDEX, ENEMY_PINK_L_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_PINK_L_02_INDEX, ENEMY_PINK_L_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_PINK_U_01_INDEX, ENEMY_PINK_U_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_PINK_U_02_INDEX, ENEMY_PINK_U_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_PINK_D_01_INDEX, ENEMY_PINK_D_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_PINK_D_02_INDEX, ENEMY_PINK_D_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_YELLOW_R_01_INDEX, ENEMY_YELLOW_R_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_YELLOW_R_02_INDEX, ENEMY_YELLOW_R_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_YELLOW_L_01_INDEX, ENEMY_YELLOW_L_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_YELLOW_L_02_INDEX, ENEMY_YELLOW_L_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_YELLOW_U_01_INDEX, ENEMY_YELLOW_U_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_YELLOW_U_02_INDEX, ENEMY_YELLOW_U_02_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_YELLOW_D_01_INDEX, ENEMY_YELLOW_D_01_IMG);
	load_sprite(data, ENEMY_CELL, ENEMY_YELLOW_D_02_INDEX, ENEMY_YELLOW_D_02_IMG);
}
