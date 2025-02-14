/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:47 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/14 18:18:42 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_animation_frame_path(char **path, char *animation, int frame)
{
	char	*frame_str;
	char	*temp;

	*path = ft_strjoin_free(*path, animation);
	*path = ft_strjoin_free(*path, "_");
	temp = ft_itoa(frame + 1);
	if (frame < 10)
		frame_str = ft_strjoin("0", temp);
	else
		frame_str = temp;
	free(temp);
	if (!frame_str)
	{
		free(frame_str);
		free(*path);
	}
	*path = ft_strjoin_free(*path, frame_str);
	free(frame_str);
}

void	*load_xpm_image(t_mlx_data *data, char *path)
{
	int	width;
	int	height;

	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	return (mlx_xpm_file_to_image(data->conn, path, &width, &height));
}

void	load_player_sprite(char **animations, int i, int *j)
{
	t_mlx_data	*data;
	char		*path;

	data = get_data();
	path = get_sprite_path(PLAYER_CELL, animations[i], i, *j);
	if (!path)
		load_player_sprites_error(data, animations, LOADING_ERROR_MSG);
	data->player_animations[i].sprites[*j] = load_xpm_image(data, path);
	data->player_animations[i].frames_count++;
	data->player_animations[i].current_frame = 0;
	data->player_animations[i].frame_timer = PLAYER_ANIMATION_DELAY;
	free(path);
	*j += 1;
}

void	load_enemy_sprite(char **animations, int i, int j, int *k)
{
	t_mlx_data	*data;
	char		*path;

	data = get_data();
	path = get_sprite_path(ENEMY_CELL, animations[j], i, *k);
	if (!path)
		load_enemies_sprites_error(data, animations, LOADING_ERROR_MSG);
	data->enemies_animations[i][j].sprites[*k] = load_xpm_image(data, path);
	data->enemies_animations[i][j].frames_count++;
	free(path);
	*k += 1;
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
