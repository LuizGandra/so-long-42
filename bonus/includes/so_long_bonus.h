/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:58 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/18 15:10:51 by lcosta-g         ###   ########.fr       */
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

// * ERROR MESSAGES
# define LOADING_ERROR_MSG "An error occurred while loading the sprites.\n"

// * MAX SCREEN SIZE
# define MAX_SCREEN_WIDTH 1920
# define MAX_SCREEN_HEIGHT 1080

// * STRUCTS
typedef struct s_enemy_data
{
	int				x;
	int				y;
	char			color;
	char			current_animation;
}					t_enemy_data;

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	int				collectible_count;
	int				exit_count;
	int				enemies_count;
	int				player_count;
	int				player_x;
	int				player_y;
	t_enemy_data	enemies_data[ENEMIES_COUNT];
}					t_map;

typedef struct s_animation
{
	void			*sprites[MAX_FRAMES];
	int				frames_count;
	int				current_frame;
	int				frame_timer;
	int				delay;
}					t_animation;

typedef struct s_mlx_data
{
	void			*conn;
	void			*window;
	int				player_movement_count;
	t_animation		player_animations[PLAYER_ANIMATIONS_COUNT];
	t_animation		enemies_animations[ENEMIES_COUNT][ENEMIES_ANIMATIONS_COUNT];
	char			current_player_animation;
	int				game_over;
	void			*static_sprites[STATIC_SPRITES_COUNT];
	t_map			map;
	t_map			flooded_map;
}					t_mlx_data;

// * STATICS
t_mlx_data			*get_data(void);

// * HOOKS
int					on_keypress(int keysym, t_mlx_data *data);
int					on_destroy(int keysym, t_mlx_data *data);
int					on_loop(t_mlx_data *data);

// * MAP
void				validate_map(t_mlx_data *data, t_map *map,
						t_map *flooded_map);
void				read_map(t_mlx_data *data, char *map_path);

// * utils
int					is_a_wall(char *line);
int					is_cell_valid(char cell);
void				update_player_data(t_map *map, int x, int y);
void				update_enemy_data(t_map *map, int x, int y);

// * RENDER
void				render_map(t_mlx_data *data);
void				render_image(t_mlx_data *data, char cell, int x, int y);
void				render_movement_counter(t_mlx_data *data, char *str);
void				render_last_player_position(t_mlx_data *data);
void				render_animation_frame(t_mlx_data *data, void *frame, int x,
						int y);

// * utils
int					check_player_on_exit(t_mlx_data *data, int x, int y);
void				load_all_assets(t_mlx_data *data);
int					get_animation_index(const char *s, int c);

// * PLAYER ACTIONS
void				handle_movement(t_mlx_data *data, char animation, int x,
						int y);

// * LOAD SPRITES
void				load_player_sprites(t_mlx_data *data);
void				load_enemies_sprites(t_mlx_data *data);
void				load_static_sprites(t_mlx_data *data);
char				*get_sprite_path(char cell, char *animation,
						int animation_i, int frame);

// * utils
void				get_animation_frame_path(char **path, char *animation,
						int frame);
void				*load_xpm_image(t_mlx_data *data, char *path);
void				load_player_sprite(char **animations, int i, int *j);
void				load_enemy_sprite(char **animations, int i, int j, int *k);
char				*get_enemy_folder(int i);

// * ANIMATIONS
void				run_player_animation(t_mlx_data *data);
void				run_enemy_animation(t_mlx_data *data, t_enemy_data *enemy,
						int enemy_i);

// * utils
void				finish_player_animation(t_mlx_data *data, int *is_finished);
void				finish_enemy_animation(t_enemy_data *enemy,
						int *is_finished);

// * GAME OVER
void				check_exit(t_mlx_data *data);
void				kill_player(t_mlx_data *data);
void				game_over(t_mlx_data *data);

// * GENERAL UTILS
void				print_movement_count(t_mlx_data *data);

// * ERRORS
void				throw_error(char *msg);
void				load_player_sprites_error(t_mlx_data *data,
						char **animations, char *msg);
void				load_enemies_sprites_error(t_mlx_data *data,
						char **animations, char *msg);

// * CLEAN
void				clean_exit(t_mlx_data *data, char *msg);
void				clean_exit_fd(int fd, char *msg);
void				clean_grid(char **mem);
void				clean_player_sprites(t_mlx_data *data, char *msg);
void				clean_enemies_sprites(t_mlx_data *data, char *msg);

#endif