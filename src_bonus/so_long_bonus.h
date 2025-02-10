/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:58 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/10 18:44:06 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// * LIBS
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// * IMAGES SIZE
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

// * ASSETS PATHS
# define BACKGROUND_IMG "./assets/background.xpm"
# define WALL_IMG "./assets/wall.xpm"
# define COLLECTIBLE_IMG "./assets/collectible.xpm"
# define EXIT_IMG "./assets/exit.xpm"
# define PLAYER_IMG "./assets/player.xpm"
# define ENEMY_IMG "./assets/enemy.xpm"
# define MOVEMENT_LOG_BG_IMG "./assets/movement_log_bg.xpm"

// * ASSETS INDEX
# define BACKGROUND_INDEX 0
# define WALL_INDEX 1
# define COLLECTIBLE_INDEX 2
# define EXIT_INDEX 3
# define PLAYER_INDEX 4
# define ENEMY_INDEX 5
# define MOVEMENT_LOG_BG_INDEX 6

// * CELLS
# define EMPTY_CELL '0'
# define WALL_CELL '1'
# define COLLECTIBLE_CELL 'C'
# define EXIT_CELL 'E'
# define PLAYER_CELL 'P'
# define ENEMY_CELL 'X'
# define WALKED_CELL '-'

// * OTHERS
# define VALID_CELLS "01CEPX"
# define MOVEMENT_LOG_STR "Movement count: "
# define MOVEMENT_LOG_COLOR 0xFFFFFF
# define MOVEMENT_LOG_X 32
# define MOVEMENT_LOG_Y 32
# define MOVEMENT_LOG_BG_LENGTH 6

// * STRUCTS
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectible_count;
	int		exit_count;
	int		player_count;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_mlx_data
{
	void	*conn;
	void	*window;
	void	*images[7];
	int		player_movement_count;
	t_map	map;
	t_map	flooded_map;
}			t_mlx_data;

// * STATICS
t_mlx_data	*get_data(void);

// * HOOKS
int			on_keypress(int keysym, t_mlx_data *data);
int			on_destroy(int keysym, t_mlx_data *data);
int			on_loop(t_mlx_data *data);

// * MAP
void		validate_map(t_mlx_data *data, t_map *map, t_map *flooded_map);
void		read_map(t_mlx_data *data, char *map_path);

// * RENDER
void		render_map(t_mlx_data *data);
void		render_image(t_mlx_data *data, char cell, int x, int y);
void		render_player_position(t_mlx_data *data, int x, int y);
void		render_movement_counter(t_mlx_data *data, char *str);
void		render_last_player_position(t_mlx_data *data);

// * PLAYER ACTIONS
void		handle_movement(t_mlx_data *data, int x, int y);

// * ANIMATIONS
void		run_player_animation(t_mlx_data *data);

// * GAME OVER
void		check_exit(t_mlx_data *data);
void		kill_player(t_mlx_data *data);

// * UTILS
int			check_player_on_exit(t_mlx_data *data, int x, int y);
int			is_a_wall(char *line);
int			is_cell_valid(char cell);
void		print_movement_count(t_mlx_data *data);

// * ERRORS
void		throw_error(char *msg);
void		clean_exit(t_mlx_data *data, char *msg);
void		clean_exit_fd(int fd, char *msg);
void		clean_grid(char **mem);

#endif