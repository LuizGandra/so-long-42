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
	t_mlx_data	*data;

	data = NULL;
	data->conn = mlx_init();
	if (!data->conn)
		return (MALLOC_ERROR);
	data->window = mlx_new_window(data->conn, WIDTH, HEIGHT, "So Long");
	if (!data->window)
		return (free(data->conn), MALLOC_ERROR);
	// * defines a hook for the KeyRelease event
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, on_keypress, data);
	// * defines a hook for the DestroyNotify event
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, on_destroy, data);

	// * loops over the pointer, triggering each hook in order of registration
	mlx_loop(data->conn);
	
	return (0);
}
