/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:37:53 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/12 18:38:02 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	run_player_animation(t_mlx_data *data, char animation)
{
	int	animation_i;
	int	i;

	animation_i = get_animation_index(PLAYER_ANIMATIONS_IDENTIFIERS, animation);
	i = 0;
	while (i < data->player_animations[animation_i].frames_count)
	{
		render_animation_frame(data,
			data->player_animations[animation_i].sprites[i++],
			data->map.player_x, data->map.player_y);
	}
	if (PLAYER_ANIMATIONS_IDENTIFIERS[animation_i] != 'x')
		render_animation_frame(data,
			data->player_animations[animation_i].sprites[0], data->map.player_x,
			data->map.player_y);
}
