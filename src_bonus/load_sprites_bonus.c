/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:30:39 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 15:19:53 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player_sprites(t_mlx_data *data)
{
	int		i;
	int		j;
	char	*path;
	char	**animations;

	i = 0;
	animations = ft_split(PLAYER_ANIMATIONS_IDENTIFIERS, ',');
	if (!animations)
		return ; // TODO handle error here
	while (i < PLAYER_ANIMATIONS_COUNT)
	{
		j = 0;
		while (j < MAX_PLAYER_ANIMATION_FRAMES)
		{
			path = get_sprite_path(PLAYER_CELL, animations[i], i, j);
			data->player_animations[i].sprites[j] = load_xpm_image(data, path);
			data->player_animations[i].frames_count++;
			data->player_animations[i].current_frame = 0;
			data->player_animations[i].frame_timer = ANIMATION_DELAY;
			free(path);
			j++;
		}
		i++;
	}
	clean_grid(animations);
}

void	load_enemies_sprites(t_mlx_data *data)
{
	int		i;
	int		j;
	int		k;
	char	*path;
	char	**animations;

	i = 0;
	animations = ft_split(ENEMIES_ANIMATIONS_IDENTIFIERS, ',');
	if (!animations)
		return ; // TODO handle error here
	while (i < ENEMIES_COUNT)
	{
		j = 0;
		while (j < ENEMIES_ANIMATIONS_COUNT)
		{
			k = 0;
			while (k < MAX_ENEMY_ANIMATION_FRAMES)
			{
				path = get_sprite_path(ENEMY_CELL, animations[i], j, k);
				data->enemies_animations[i][j].sprites[k] = load_xpm_image(data,
						path);
				data->enemies_animations[i][j].frames_count++;
				free(path);
				k++;
			}
			j++;
		}
		i++;
	}
	clean_grid(animations);
}

void	load_static_sprites(t_mlx_data *data)
{
	data->static_sprites[BACKGROUND_INDEX] = load_xpm_image(data, BACKGROUND_IMG);
	data->static_sprites[WALL_INDEX] = load_xpm_image(data, WALL_IMG);
	data->static_sprites[COLLECTIBLE_INDEX] = load_xpm_image(data, COLLECTIBLE_IMG);
	data->static_sprites[EXIT_INDEX] = load_xpm_image(data, EXIT_IMG);
	data->static_sprites[MOVEMENT_LOG_BG_INDEX] = load_xpm_image(data, MOVEMENT_LOG_BG_IMG);
}
