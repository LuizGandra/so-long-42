#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

# define MALLOC_ERROR 1

# define WIDTH 640
# define HEIGHT 288

typedef struct s_mlx_data
{
	void	*conn;
	void	*window;
}			t_mlx_data;

#endif