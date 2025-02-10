/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:02:46 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/10 18:05:15 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	throw_error(char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
	exit(EXIT_FAILURE);
}

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
	ft_printf("Error\n");
	ft_printf(msg);
	clean_grid(data->map.grid);
	clean_grid(data->flooded_map.grid);
	if (data->window)
		mlx_destroy_window(data->conn, data->window);
	if (data->conn)
		mlx_destroy_display(data->conn);
	exit(EXIT_FAILURE);
}

void	clean_exit_fd(int fd, char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
	close(fd);
	exit(EXIT_FAILURE);
}
