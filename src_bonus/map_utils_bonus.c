/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:58:24 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/12 11:59:02 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_a_wall(char *line)
{
	while (*line)
	{
		if (*line++ != WALL_CELL)
			return (0);
	}
	return (1);
}

int	is_cell_valid(char cell)
{
	if (!ft_strchr(VALID_CELLS, cell))
		return (0);
	return (1);
}
