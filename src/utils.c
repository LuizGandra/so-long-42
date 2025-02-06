/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:17 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/06 18:15:49 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	throw_error(char *msg)
{
	ft_printf(msg);
	exit(EXIT_FAILURE);
}

int	check_player_on_exit(t_mlx_data *data, int x, int y)
{
	if (data->map.player_x == x && data->map.player_y == y)
		return (1);
	return (0);
}