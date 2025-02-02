#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
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
	void	*images[5];
}			t_mlx_data;

#endif