/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:17 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/13 15:13:18 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_movement_count(t_mlx_data *data)
{
	char	*str;
	char	*count_str;

	count_str = ft_itoa(data->player_movement_count);
	if (!count_str)
	{
		free(count_str);
		on_destroy(0, data);
	}
	str = ft_strjoin(MOVEMENT_LOG_STR, count_str);
	if (!str)
	{
		free(str);
		free(count_str);
		on_destroy(0, data);
	}
	render_movement_counter(data, str);
	free(count_str);
	free(str);
}
