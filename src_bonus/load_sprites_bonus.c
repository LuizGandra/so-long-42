/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:30:39 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/14 18:20:44 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player_sprites(t_mlx_data *data)
{
	int		i;
	int		j;
	char	**animations;

	i = 0;
	animations = ft_split(PLAYER_ANIMATIONS_IDS, ',');
	if (!animations)
		load_player_sprites_error(data, animations, LOADING_ERROR_MSG);
	while (i < PLAYER_ANIMATIONS_COUNT)
	{
		j = 0;
		while (j < MAX_PLAYER_ANIMATION_FRAMES)
			load_player_sprite(animations, i, &j);
		i++;
	}
	clean_grid(animations);
}

void	load_enemies_sprites(t_mlx_data *data)
{
	int		i;
	int		j;
	int		k;
	char	**animations;

	i = 0;
	animations = ft_split(ENEMIES_ANIMATIONS_IDS, ',');
	if (!animations)
		load_enemies_sprites_error(data, animations, LOADING_ERROR_MSG);
	while (i < ENEMIES_COUNT)
	{
		j = 0;
		while (j < ENEMIES_ANIMATIONS_COUNT)
		{
			k = 0;
			while (k < MAX_ENEMIES_ANIMATION_FRAMES)
				load_enemy_sprite(animations, i, j, &k);
			j++;
		}
		i++;
	}
	clean_grid(animations);
}

void	load_static_sprites(t_mlx_data *data)
{
	data->static_sprites[BACKGROUND_INDEX] = load_xpm_image(data,
			BACKGROUND_IMG);
	data->static_sprites[WALL_INDEX] = load_xpm_image(data, WALL_IMG);
	data->static_sprites[COLLECTIBLE_INDEX] = load_xpm_image(data,
			COLLECTIBLE_IMG);
	data->static_sprites[EXIT_INDEX] = load_xpm_image(data, EXIT_IMG);
	data->static_sprites[MOVEMENT_LOG_BG_INDEX] = load_xpm_image(data,
			MOVEMENT_LOG_BG_IMG);
}

char	*get_sprite_path(char cell, char *animation, int animation_i, int frame)
{
	char	*path;

	if (cell == PLAYER_CELL)
		path = ft_strjoin(BASE_PATH, "player/player_");
	else if (cell == ENEMY_CELL)
	{
		path = ft_strjoin(BASE_PATH, "enemies/");
		path = ft_strjoin_free(path, get_enemy_folder(animation_i));
		path = ft_strjoin_free(path, "enemy_");
	}
	get_animation_frame_path(&path, animation, frame);
	path = ft_strjoin_free(path, ".xpm");
	if (!path)
		return (free(path), NULL);
	return (path);
}
