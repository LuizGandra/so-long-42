#include "so_long.h"

void	throw_error(char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
	exit(EXIT_FAILURE);
}

void clean_exit(t_mlx_data *data, char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
	clean_grid(data->map.grid);
	clean_grid(data->validation_map.grid);
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