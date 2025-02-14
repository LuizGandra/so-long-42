/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:45:55 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/14 18:54:54 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_enemy(t_mlx_data *data, t_enemy_data *enemy, int enemy_i);
static void	get_enemy_next_move(t_mlx_data *data, t_enemy_data *enemy);

void	move_enemies(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.enemies_count)
	{
		move_enemy(data, &data->map.enemies_data[i], i);
		i++;
	}
}

static void	move_enemy(t_mlx_data *data, t_enemy_data *enemy, int enemy_i)
{
	get_enemy_next_move(data, enemy);
	run_enemy_animation(data, enemy, enemy_i);
}

// TODO i need to remove the latest enemy position after move to the next one
// *Bresenham Algorithm's implementation
static void	get_enemy_next_move(t_mlx_data *data, t_enemy_data *enemy)
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	static int	error;

	if (enemy->x == data->map.player_x && enemy->y == data->map.player_y)
		return ;
	dx = enemy->x - data->map.player_x;
	dy = enemy->y - data->map.player_y;
	if (dx < 0)
		sx = -1;
	else
		sx = 1;
	if (dy < 0)
		sy = -1;
	else
		sy = 1;
	error = dx - dy;
	if (error * 2 > -dy)
	{
		error -= dy;
		enemy->x += sx; // * move on x axis
		if (sx > 0)
			enemy->current_animation = 'r';
		else
			enemy->current_animation = 'l';
	}
	if (error * 2 < dx)
	{
		error += dx;
		enemy->y += sy; // * move on y axis
		if (sy > 0)
			enemy->current_animation = 'd';
		else
			enemy->current_animation = 'u';
	}
}
