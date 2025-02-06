#include "so_long.h"

static void	load_XPM_images(t_mlx_data *data);
static void	render_image(t_mlx_data *data, char cell, int x, int y);

void	render_map(t_mlx_data *data)
{
	char	**grid;
	int	x;
	int	y;

	// * load images
	load_XPM_images(data);
	// * render background
	mlx_put_image_to_window(data->conn, data->window, data->images[BACKGROUND_INDEX], 0, 0);
	grid = data->map.grid;
	x = 0;
	y = 0;
	while (grid[y])
	{
		while (grid[y][x])
		{
			render_image(data, grid[y][x], x, y);
			x++;
		}
		y++;
	}
}

static void	load_XPM_images(t_mlx_data *data)
{
	int	WIDTH = IMG_WIDTH;
	int	HEIGHT = IMG_HEIGHT;

	data->images[BACKGROUND_INDEX] = mlx_xpm_file_to_image(data->conn, BACKGROUND_IMG, &WIDTH, &HEIGHT);
	data->images[WALL_INDEX] = mlx_xpm_file_to_image(data->conn, WALL_IMG, &WIDTH, &HEIGHT);
	data->images[COLLECTIBLE_INDEX] = mlx_xpm_file_to_image(data->conn, COLLECTIBLE_IMG, &WIDTH, &HEIGHT);
	data->images[EXIT_INDEX] = mlx_xpm_file_to_image(data->conn, EXIT_IMG, &WIDTH, &HEIGHT);
	data->images[PLAYER_INDEX] = mlx_xpm_file_to_image(data->conn, PLAYER_IMG, &WIDTH, &HEIGHT);
}

static void render_image(t_mlx_data *data, char cell, int x, int y)
{
	void	*image;

	if (cell == '1')
		image = data->images[WALL_INDEX];
	else if (cell == 'C')
		image = data->images[COLLECTIBLE_INDEX];
	else if (cell == 'E')
		image = data->images[EXIT_INDEX];
	else if (cell == 'P')
		image = data->images[PLAYER_INDEX];
	else
		return ;
	mlx_put_image_to_window(data->conn, data->window, image, x * IMG_WIDTH, y * IMG_HEIGHT);
}