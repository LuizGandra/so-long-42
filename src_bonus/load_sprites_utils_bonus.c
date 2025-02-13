/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:47 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 11:14:00 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_sprite_path(char cell, char *animation, int animation_i,
		int frame)
{
	char	*path;
	char	*frame_str;

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
	if (frame < 10)
		frame_str = ft_strjoin("0", ft_itoa(frame + 1));
	else
		frame_str = ft_itoa(frame + 1);
	if (!frame_str)
		return (NULL); // TODO handle error
	path = ft_strjoin_free(path, frame_str);
	path = ft_strjoin_free(path, ".xpm");
	if (!path)
		return (NULL); // TODO handle error
	return (path);
}

void	*load_xpm_image(t_mlx_data *data, char *path)
{
	int	width;
	int	height;

	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	return mlx_xpm_file_to_image(data->conn, path, &width, &height);
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
