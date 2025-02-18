/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:50:21 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 14:08:14 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	finish_player_animation(t_mlx_data *data, int *is_finished)
{
	if (*is_finished)
	{
		data->current_player_animation = '\0';
		*is_finished = 0;
	}
}

void	finish_enemy_animation(t_enemy_data *enemy, int *is_finished)
{
	if (*is_finished)
	{
		enemy->current_animation = '\0';
		*is_finished = 0;
	}
}
