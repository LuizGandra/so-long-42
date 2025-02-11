/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:58 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/11 17:29:50 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// * LIBS
# include "libft.h"
# include "mlx.h"
# include "so_long_sprites_bonus.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// * CELLS
# define EMPTY_CELL '0'
# define WALL_CELL '1'
# define COLLECTIBLE_CELL 'C'
# define EXIT_CELL 'E'
# define PLAYER_CELL 'P'
# define ENEMY_CELL 'X'
# define WALKED_CELL '-'
# define VALID_CELLS "01CEPX"

// * MOVEMENT LOG
# define MOVEMENT_LOG_STR "Movement count: "
# define MOVEMENT_LOG_COLOR 0xFFFFFF
# define MOVEMENT_LOG_X 32
# define MOVEMENT_LOG_Y 32
# define MOVEMENT_LOG_BG_LENGTH 6

// * ANIMATION
# define MAX_FRAMES 4
# define ENEMIES_COUNT 4
# define PLAYER_ANIMATIONS_COUNT 5
# define ENEMIES_ANIMATIONS_COUNT 4
# define STATIC_SPRITES_COUNT 5

# define PLAYER_ANIMATIONS_IDENTIFIERS "rludx"
# define ENEMIES_ANIMATIONS_IDENTIFIERS "rlud"

// * ANIMATION DELAYS
# define PLAYER_DELAY 60

// * STRUCTS
typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectible_count;
	int			exit_count;
	int			player_count;
	int			player_x;
	int			player_y;
}				t_map;

typedef struct s_animation
{
	void		*sprites[MAX_FRAMES];
	int			frames_count;
	int			delay;
}				t_animation;

typedef struct s_mlx_data
{
	void		*conn;
	void		*window;
	int			player_movement_count;
	t_animation	player_animations[PLAYER_ANIMATIONS_COUNT];
	t_animation	enemies_animations[ENEMIES_COUNT][ENEMIES_ANIMATIONS_COUNT];
	void		*static_sprites[STATIC_SPRITES_COUNT];
	t_map		map;
	t_map		flooded_map;
}				t_mlx_data;

// * STATICS
t_mlx_data		*get_data(void);

// * HOOKS
int				on_keypress(int keysym, t_mlx_data *data);
int				on_destroy(int keysym, t_mlx_data *data);
int				on_loop(t_mlx_data *data);

// * MAP
void			validate_map(t_mlx_data *data, t_map *map, t_map *flooded_map);
void			read_map(t_mlx_data *data, char *map_path);

// * RENDER
void			render_map(t_mlx_data *data);
void			render_image(t_mlx_data *data, char cell, int x, int y);
void			render_player_position(t_mlx_data *data, int x, int y);
void			render_movement_counter(t_mlx_data *data, char *str);
void			render_last_player_position(t_mlx_data *data);

// * PLAYER ACTIONS
void			handle_movement(t_mlx_data *data, int x, int y);

// * LOAD SPRITES
void			load_player_sprites(t_mlx_data *data);
void			load_enemies_sprites(t_mlx_data *data);
void			load_static_sprites(t_mlx_data *data);

// * LOAD SPRITES UTILS
char			*get_animated_sprite_path(char cell, char animation,
					int animation_i, int frame);
void			load_xpm_image(t_mlx_data *data, char *path, void **sprite);
char			*get_enemy_folder(int i);

// * ANIMATIONS
void			run_player_animation(t_mlx_data *data);

// * GAME OVER
void			check_exit(t_mlx_data *data);
void			kill_player(t_mlx_data *data);

// * GENERAL UTILS
int				check_player_on_exit(t_mlx_data *data, int x, int y);
int				is_a_wall(char *line);
int				is_cell_valid(char cell);
void			print_movement_count(t_mlx_data *data);

// * ERRORS
void			throw_error(char *msg);
void			clean_exit(t_mlx_data *data, char *msg);
void			clean_exit_fd(int fd, char *msg);
void			clean_grid(char **mem);

#endif