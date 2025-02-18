/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:37:53 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 15:31:30 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	run_player_animation(t_mlx_data *data)
{
	t_animation	*animation_data;
	static int	is_finished;
	int			animation_i;

	animation_i = get_animation_index(PLAYER_ANIMATIONS_IDS,
			data->current_player_animation);
	animation_data = &data->player_animations[animation_i];
	if (animation_data->frame_timer == animation_data->delay)
	{
		animation_data->frame_timer = 0;
		render_animation_frame(data,
			animation_data->sprites[animation_data->current_frame],
			data->map.player_x, data->map.player_y);
		if (is_finished)
			finish_player_animation(data, &is_finished);
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

void	run_enemy_animation(t_mlx_data *data, t_enemy_data *enemy, int enemy_i)
{
	t_animation	*animation_data;
	int			animation_i;

	animation_i = get_animation_index(ENEMIES_ANIMATIONS_IDS,
			enemy->current_animation);
	animation_data = &data->enemies_animations[enemy_i][animation_i];
	if (animation_data->frame_timer == animation_data->delay)
	{
		animation_data->frame_timer = 0;
		render_animation_frame(data,
			animation_data->sprites[animation_data->current_frame],
			enemy->x, enemy->y);
		animation_data->current_frame++;
		if (animation_data->current_frame == MAX_ENEMIES_ANIMATION_FRAMES)
			animation_data->current_frame = 0;
	}
	else
		animation_data->frame_timer++;
}
