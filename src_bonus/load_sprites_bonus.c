/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:30:39 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/11 17:30:39 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player_sprites(t_mlx_data *data)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (i < PLAYER_ANIMATIONS_COUNT)
	{
		j = 0;
		// TODO improve this and check the logic for MAX_FRAMES
		while (j < MAX_FRAMES)
		{
			path = get_animated_sprite_path(PLAYER_CELL,
					PLAYER_ANIMATIONS_IDENTIFIERS[i], i, j);
			load_xpm_image(data, path, data->player_animations[i].sprites[j]);
			free(path);
			j++;
		}
		i++;
	}
}

// TODO improve this and check the logic for MAX_FRAMES
void	load_enemies_sprites(t_mlx_data *data)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	i = 0;
	while (i < ENEMIES_COUNT)
	{
		j = 0;
		while (j < ENEMIES_ANIMATIONS_COUNT)
		{
			k = 0;
			while (k < MAX_FRAMES / 2)
			{
				path = get_animated_sprite_path(PLAYER_CELL,
						ENEMIES_ANIMATIONS_IDENTIFIERS[i], j, k);
				load_xpm_image(data, path,
					data->player_animations[j].sprites[k]);
				free(path);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	load_static_sprites(t_mlx_data *data)
{
	load_xpm_image(data, BACKGROUND_IMG,
		data->static_sprites[BACKGROUND_INDEX]);
	load_xpm_image(data, WALL_IMG, data->static_sprites[WALL_INDEX]);
	load_xpm_image(data, COLLECTIBLE_IMG,
		data->static_sprites[COLLECTIBLE_INDEX]);
	load_xpm_image(data, EXIT_IMG, data->static_sprites[EXIT_INDEX]);
	load_xpm_image(data, MOVEMENT_LOG_BG_IMG,
		data->static_sprites[MOVEMENT_LOG_BG_INDEX]);
}
