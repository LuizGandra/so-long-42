/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:56:55 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 19:18:40 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_player_on_exit(t_mlx_data *data, int x, int y)
{
	if (data->map.player_x == x && data->map.player_y == y)
		return (1);
	return (0);
}

void	load_all_assets(t_mlx_data *data)
{
	load_player_sprites(data);
	load_enemies_sprites(data);
	load_static_sprites(data);
}

int	get_animation_index(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s && *s != (unsigned char)c)
	{
		if (*s != ',')
			i++;
		s++;
	}
	if (*s == (unsigned char)c)
		return (i);
	return (-1);
}
