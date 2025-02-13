/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:37:53 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 13:24:34 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	run_player_animation(t_mlx_data *data, char animation)
{
	int	i;
	int	animation_i;

	i = 0;
	animation_i = get_animation_index(PLAYER_ANIMATIONS_IDENTIFIERS, animation);
	while (i < data->player_animations[animation_i].frames_count)
	{
		data->frame_timer = 0;
		if (data->frame_timer == ANIMATION_DELAY)
		{
			render_animation_frame(data,
				data->player_animations[animation_i].sprites[i++],
				data->map.player_x, data->map.player_y);
			data->frame_timer = 0;
		}
		else
			break;
	}
	if (animation != 'x')
		render_animation_frame(data,
			data->player_animations[animation_i].sprites[DEFAULT_SPRITE_INDEX],
			data->map.player_x, data->map.player_y);
}
