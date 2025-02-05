#include "so_long.h"

int	on_keypress(int keysym, t_mlx_data *data)
{
	(void)data;
	if (keysym == XK_Up)
	{
		// TODO
		ft_printf("Keysym: %i\n", keysym);
	}
	else if (keysym == XK_Left)
	{
		// TODO
		ft_printf("Keysym: %i\n", keysym);
	}
	else if (keysym == XK_Down)
	{
		// TODO
		ft_printf("Keysym: %i\n", keysym);
	}
	else if (keysym == XK_Right)
	{
		// TODO
		ft_printf("Keysym: %i\n", keysym);
	}
	return (EXIT_SUCCESS);
}

int	on_destroy(int keysym, t_mlx_data *data)
{
	ft_printf("Keysym: %i\n", keysym);
	mlx_destroy_window(data->conn, data->window);
	mlx_destroy_display(data->conn);
	free(data->conn);
	exit(EXIT_SUCCESS);
	return(EXIT_SUCCESS);
}