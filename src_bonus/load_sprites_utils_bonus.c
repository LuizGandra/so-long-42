/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:47 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 19:36:27 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// TODO the lines of this function (improve the logic on the use of ft_itoa)
char	*get_sprite_path(char cell, char *animation, int animation_i, int frame)
{
	char	*path;
	char	*frame_str;
	char	*temp;

	if (cell == PLAYER_CELL)
		path = ft_strjoin(BASE_PATH, "player/player_");
	else if (cell == ENEMY_CELL)
	{
		path = ft_strjoin(BASE_PATH, "enemies/");
		path = ft_strjoin_free(path, get_enemy_folder(animation_i));
		path = ft_strjoin_free(path, "enemy_");
	}
	path = ft_strjoin_free(path, animation);
	path = ft_strjoin_free(path, "_");
	temp = ft_itoa(frame + 1);
	if (frame < 10)
		frame_str = ft_strjoin("0", temp);
	else
		frame_str = temp;
	free(temp);
	if (!frame_str)
		return (free(frame_str), free(path), NULL);
	path = ft_strjoin_free(path, frame_str);
	free(frame_str);
	path = ft_strjoin_free(path, ".xpm");
	if (!path)
		return (free(path), NULL);
	return (path);
}

void	*load_xpm_image(t_mlx_data *data, char *path)
{
	int	width;
	int	height;

	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	return (mlx_xpm_file_to_image(data->conn, path, &width, &height));
}

char	*get_enemy_folder(int i)
{
	if (i == ENEMY_RED_INDEX)
		return ("red/");
	if (i == ENEMY_BLUE_INDEX)
		return ("blue/");
	else if (i == ENEMY_PINK_INDEX)
		return ("pink/");
	else
		return ("yellow/");
}

void	load_player_sprite(t_mlx_data *data, char **animations, int i, int *j)
{
	char	*path;
	path = get_sprite_path(PLAYER_CELL, animations[i], i, *j);
	if (!path)
		load_player_sprites_error(data, animations, LOADING_ERROR_MSG);
	data->player_animations[i].sprites[*j] = load_xpm_image(data, path);
	data->player_animations[i].frames_count++;
	data->player_animations[i].current_frame = 0;
	data->player_animations[i].frame_timer = ANIMATION_DELAY;
	free(path);
	*j += 1;
}

void	load_enemy_sprite(t_mlx_data *data, char **animations, int i, int j,
		int *k)
{
	char	*path;
	path = get_sprite_path(ENEMY_CELL, animations[i], j, *k);
	if (!path)
		load_enemies_sprites_error(data, animations, LOADING_ERROR_MSG);
	data->enemies_animations[i][j].sprites[*k] = load_xpm_image(data, path);
	data->enemies_animations[i][j].frames_count++;
	free(path);
	*k += 1;
}
