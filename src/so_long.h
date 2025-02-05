/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:58 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/05 19:45:33 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// * LIBS
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// * WINDOW SIZE
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 288

// * IMAGES SIZE
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

// * ASSETS PATHS
# define BACKGROUND_IMG "./assets/background.xpm"
# define WALL_IMG "./assets/wall.xpm"
# define COLLECTIBLE_IMG "./assets/collectible.xpm"
# define EXIT_IMG "./assets/exit.xpm"
# define PLAYER_IMG "./assets/player.xpm"

// * ASSETS INDEX
# define BACKGROUND_INDEX 0
# define WALL_INDEX 1
# define COLLECTIBLE_INDEX 2
# define EXIT_INDEX 3
# define PLAYER_INDEX 4

// * STRUCTS
typedef struct s_map
{
	int		width;
	int		height;
	int 	collectible_count;
	int 	exit_count;
	int 	player_count;
	char	**grid;
}			t_map;

typedef struct s_mlx_data
{
	void	*conn;
	void	*window;
	void	*images[5];
	t_map	map;
}			t_mlx_data;

// * UTILS
void	throw_error(char *msg);

// * MAP
void	validate_map(t_map *map);
void	read_map(t_mlx_data *data, char *map_path);


// * HOOKS
int	on_keypress(int keysym, t_mlx_data *data);
int	on_destroy(int keysym, t_mlx_data *data);

#endif