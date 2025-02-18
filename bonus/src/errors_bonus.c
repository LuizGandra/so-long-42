/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:02:46 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 19:19:59 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	throw_error(char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
	exit(EXIT_FAILURE);
}

void	load_player_sprites_error(t_mlx_data *data, char **animations,
		char *msg)
{
	clean_grid(animations);
	clean_player_sprites(data, msg);
}

void	load_enemies_sprites_error(t_mlx_data *data, char **animations,
		char *msg)
{
	clean_grid(animations);
	clean_player_sprites(data, NULL);
	clean_enemies_sprites(data, msg);
}
