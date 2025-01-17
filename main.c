#include "so_long.h"

int	on_keypress(t_mlx_data *data)
{
	mlx_destroy_window(data->conn, data->window);
	mlx_destroy_display(data->conn);
	free(data->conn);
	exit(0);
	return (0);
}

int	on_destroy(int keysym, t_mlx_data *data)
{
	printf("Pressed key: %d\n", keysym);
	printf("Data address: %p\n", data);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.conn = mlx_init();
	if (!data.conn)
		return (MALLOC_ERROR);
	printf("testeee");
	data.window = mlx_new_window(data.conn, WIDTH, HEIGHT, "So Long");
	if (!data.window)
		return (free(data.conn), MALLOC_ERROR);
	mlx_hook(data.window, KeyRelease, KeyReleaseMask, on_keypress, &data);
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, on_destroy, &data);
	mlx_loop(data.conn);
	
	return (0);
}
