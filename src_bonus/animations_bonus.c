/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:37:53 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 16:13:58 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	run_player_animation(t_mlx_data *data)
{
	t_animation	*animation_data;
	static int	is_finished;
	int			animation_i;

	animation_i = get_animation_index(PLAYER_ANIMATIONS_IDENTIFIERS,
			data->current_player_animation);
	animation_data = &data->player_animations[animation_i];
	if (animation_data->frame_timer == ANIMATION_DELAY)
	{
		animation_data->frame_timer = 0;
		render_animation_frame(data,
			animation_data->sprites[animation_data->current_frame],
			data->map.player_x, data->map.player_y);
		ft_printf("Frame: %i\n", animation_data->current_frame);
		if (is_finished)
		{
			data->current_player_animation = '\0';
			animation_data->current_frame = 0;
			is_finished = 0;
		}
		animation_data->current_frame++;
		if (animation_data->current_frame == MAX_PLAYER_ANIMATION_FRAMES)
		{
			animation_data->current_frame = 0;
			is_finished = 1;
		}
	}
	else
		animation_data->frame_timer++;
}
