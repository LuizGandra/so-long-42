/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:46:50 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 13:50:23 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_grid(char **mem)
{
	char	**temp;

	temp = mem;
	while (*temp)
		free(*temp++);
	free(mem);
}

void	clean_exit(t_mlx_data *data, char *msg)
{
	clean_grid(data->map.grid);
	clean_grid(data->flooded_map.grid);
	if (data->window)
		mlx_destroy_window(data->conn, data->window);
	if (data->conn)
		mlx_destroy_display(data->conn);
	throw_error(msg);
}

void	clean_exit_fd(int fd, char *msg)
{
	close(fd);
	throw_error(msg);
}

void	clean_player_sprites(t_mlx_data *data, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER_ANIMATIONS_COUNT)
	{
		j = 0;
		while (j < MAX_PLAYER_ANIMATION_FRAMES)
		{
			if (data->player_animations[i].sprites[j])
				mlx_destroy_image(data->conn,
					data->player_animations[i].sprites[j++]);
		}
		i++;
	}
	if (msg)
		clean_exit(data, msg);
}

void	clean_enemies_sprites(t_mlx_data *data, char *msg)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < ENEMIES_COUNT)
	{
		j = 0;
		while (j < ENEMIES_ANIMATIONS_COUNT)
		{
			k = 0;
			while (k < MAX_ENEMIES_ANIMATION_FRAMES)
			{
				if (data->enemies_animations[i][j].sprites[k])
					mlx_destroy_image(data->conn,
						data->enemies_animations[i][j].sprites[k++]);
			}
			j++;
		}
		i++;
	}
	if (msg)
		clean_exit(data, msg);
}
