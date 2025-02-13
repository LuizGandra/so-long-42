/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:18:45 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 15:13:18 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_exit(t_mlx_data *data)
{
	if (!data->map.collectible_count)
	{
		ft_printf("\n=================== Congratulations! ==================="
			"\n");
		ft_printf("You won with %i movements.", data->player_movement_count);
		ft_printf("\n======================================================="
			"\n\n");
		on_destroy(0, data);
	}
}

void	kill_player(t_mlx_data *data)
{
	ft_printf("\n====================== Game Over! ======================\n");
	ft_printf("You lost with %i moves with only %i collectibles remaining.",
		data->player_movement_count, data->map.collectible_count);
	ft_printf("\n=======================================================\n\n");
	on_destroy(0, data);
}
