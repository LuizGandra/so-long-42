/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:18:45 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 17:49:29 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_exit(t_mlx_data *data)
{
	if (!data->map.collectible_count)
	{
		ft_printf("\033[1;32m" "\nCONGRATULATIONS!\n" "\033[0m");
		ft_printf("\033[32m" "You won with %i movements.\n\n" "\033[0m",
			data->player_movement_count);
		on_destroy(0, data);
	}
}

void	kill_player(t_mlx_data *data)
{
	data->game_over = 1;
	data->current_player_animation = DEATH_ID;
}

void	game_over(t_mlx_data *data)
{
	ft_printf("\033[1;31m" "\nGAME OVER!\n" "\033[0m");
	ft_printf("\033[31m"
		"You lost with %i moves with %i collectibles remaining.\n\n"
		"\033[0m", data->player_movement_count, data->map.collectible_count);
	on_destroy(0, data);
}
