/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprites_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:25:28 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/11 12:23:44 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_SPRITES_BONUS_H
# define SO_LONG_SPRITES_BONUS_H

// * IMAGES SIZE
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

// * STATIC SPRITE INDEXES
# define BACKGROUND_INDEX 0
# define WALL_INDEX 1
# define COLLECTIBLE_INDEX 2
# define EXIT_INDEX 3
# define MOVEMENT_LOG_BG_INDEX 4

// * PLAYER ANIMATION INDEXES
# define PLAYER_R_01_INDEX 0
# define PLAYER_R_02_INDEX 1
# define PLAYER_R_03_INDEX 2
# define PLAYER_R_04_INDEX 3

# define PLAYER_L_01_INDEX 4
# define PLAYER_L_02_INDEX 5
# define PLAYER_L_03_INDEX 6
# define PLAYER_L_04_INDEX 7

# define PLAYER_U_01_INDEX 8
# define PLAYER_U_02_INDEX 9
# define PLAYER_U_03_INDEX 10
# define PLAYER_U_04_INDEX 11

# define PLAYER_D_01_INDEX 12
# define PLAYER_D_02_INDEX 13
# define PLAYER_D_03_INDEX 14
# define PLAYER_D_04_INDEX 15

# define PLAYER_DEATH_01_INDEX 16
# define PLAYER_DEATH_02_INDEX 17
# define PLAYER_DEATH_03_INDEX 18
# define PLAYER_DEATH_04_INDEX 19

// * RED ENEMY ANIMATION INDEXES
# define ENEMY_RED_R_01_INDEX 0
# define ENEMY_RED_R_02_INDEX 1

# define ENEMY_RED_L_01_INDEX 2
# define ENEMY_RED_L_02_INDEX 3

# define ENEMY_RED_U_01_INDEX 4
# define ENEMY_RED_U_02_INDEX 5

# define ENEMY_RED_D_01_INDEX 6
# define ENEMY_RED_D_02_INDEX 7

// * BLUE ENEMY ANIMATION INDEXES
# define ENEMY_BLUE_R_01_INDEX 8
# define ENEMY_BLUE_R_02_INDEX 9

# define ENEMY_BLUE_L_01_INDEX 10
# define ENEMY_BLUE_L_02_INDEX 11

# define ENEMY_BLUE_U_01_INDEX 12
# define ENEMY_BLUE_U_02_INDEX 13

# define ENEMY_BLUE_D_01_INDEX 14
# define ENEMY_BLUE_D_02_INDEX 15

// * PINK ENEMY ANIMATION INDEXES
# define ENEMY_PINK_R_01_INDEX 16
# define ENEMY_PINK_R_02_INDEX 17

# define ENEMY_PINK_L_01_INDEX 18
# define ENEMY_PINK_L_02_INDEX 19

# define ENEMY_PINK_U_01_INDEX 20
# define ENEMY_PINK_U_02_INDEX 21

# define ENEMY_PINK_D_01_INDEX 22
# define ENEMY_PINK_D_02_INDEX 23

// * YELLOW ENEMY ANIMATION INDEXES
# define ENEMY_YELLOW_R_01_INDEX 24
# define ENEMY_YELLOW_R_02_INDEX 25

# define ENEMY_YELLOW_L_01_INDEX 26
# define ENEMY_YELLOW_L_02_INDEX 27

# define ENEMY_YELLOW_U_01_INDEX 28
# define ENEMY_YELLOW_U_02_INDEX 29

# define ENEMY_YELLOW_D_01_INDEX 30
# define ENEMY_YELLOW_D_02_INDEX 31

// * MAP SPRITES
# define BACKGROUND_IMG "./assets/map/background.xpm"
# define WALL_IMG "./assets/map/wall.xpm"
# define COLLECTIBLE_IMG "./assets/map/collectible.xpm"
# define EXIT_IMG "./assets/map/exit.xpm"

// * UI SPRITES
# define MOVEMENT_LOG_BG_IMG "./assets/ui/movement_log_bg.xpm"

// * RED ENEMY SPRITES
# define ENEMY_RED_R_01_IMG "./assets/enemies/red/enemy_r_01.xpm"
# define ENEMY_RED_R_02_IMG "./assets/enemies/red/enemy_r_02.xpm"

# define ENEMY_RED_L_01_IMG "./assets/enemies/red/enemy_l_01.xpm"
# define ENEMY_RED_L_02_IMG "./assets/enemies/red/enemy_l_02.xpm"

# define ENEMY_RED_U_01_IMG "./assets/enemies/red/enemy_u_01.xpm"
# define ENEMY_RED_U_02_IMG "./assets/enemies/red/enemy_u_02.xpm"

# define ENEMY_RED_D_01_IMG "./assets/enemies/red/enemy_d_01.xpm"
# define ENEMY_RED_D_02_IMG "./assets/enemies/red/enemy_d_02.xpm"

// * BLUE ENEMY SPRITES
# define ENEMY_BLUE_R_01_IMG "./assets/enemies/blue/enemy_r_01.xpm"
# define ENEMY_BLUE_R_02_IMG "./assets/enemies/blue/enemy_r_02.xpm"

# define ENEMY_BLUE_L_01_IMG "./assets/enemies/blue/enemy_l_01.xpm"
# define ENEMY_BLUE_L_02_IMG "./assets/enemies/blue/enemy_l_02.xpm"

# define ENEMY_BLUE_U_01_IMG "./assets/enemies/blue/enemy_u_01.xpm"
# define ENEMY_BLUE_U_02_IMG "./assets/enemies/blue/enemy_u_02.xpm"

# define ENEMY_BLUE_D_01_IMG "./assets/enemies/blue/enemy_d_01.xpm"
# define ENEMY_BLUE_D_02_IMG "./assets/enemies/blue/enemy_d_02.xpm"

// * PINK ENEMY SPRITES
# define ENEMY_PINK_R_01_IMG "./assets/enemies/pink/enemy_r_01.xpm"
# define ENEMY_PINK_R_02_IMG "./assets/enemies/pink/enemy_r_02.xpm"

# define ENEMY_PINK_L_01_IMG "./assets/enemies/pink/enemy_l_01.xpm"
# define ENEMY_PINK_L_02_IMG "./assets/enemies/pink/enemy_l_02.xpm"

# define ENEMY_PINK_U_01_IMG "./assets/enemies/pink/enemy_u_01.xpm"
# define ENEMY_PINK_U_02_IMG "./assets/enemies/pink/enemy_u_02.xpm"

# define ENEMY_PINK_D_01_IMG "./assets/enemies/pink/enemy_d_01.xpm"
# define ENEMY_PINK_D_02_IMG "./assets/enemies/pink/enemy_d_02.xpm"

// * YELLOW ENEMY SPRITES
# define ENEMY_YELLOW_R_01_IMG "./assets/enemies/yellow/enemy_r_01.xpm"
# define ENEMY_YELLOW_R_02_IMG "./assets/enemies/yellow/enemy_r_02.xpm"

# define ENEMY_YELLOW_L_01_IMG "./assets/enemies/yellow/enemy_l_01.xpm"
# define ENEMY_YELLOW_L_02_IMG "./assets/enemies/yellow/enemy_l_02.xpm"

# define ENEMY_YELLOW_U_01_IMG "./assets/enemies/yellow/enemy_u_01.xpm"
# define ENEMY_YELLOW_U_02_IMG "./assets/enemies/yellow/enemy_u_02.xpm"

# define ENEMY_YELLOW_D_01_IMG "./assets/enemies/yellow/enemy_d_01.xpm"
# define ENEMY_YELLOW_D_02_IMG "./assets/enemies/yellow/enemy_d_02.xpm"

// * PLAYER SPRITES
# define PLAYER_R_01_IMG "./assets/player/player_r_01.xpm"
# define PLAYER_R_02_IMG "./assets/player/player_r_03.xpm"
# define PLAYER_R_03_IMG "./assets/player/player_r_02.xpm"
# define PLAYER_R_04_IMG "./assets/player/player_r_04.xpm"

# define PLAYER_L_01_IMG "./assets/player/player_l_01.xpm"
# define PLAYER_L_02_IMG "./assets/player/player_l_03.xpm"
# define PLAYER_L_03_IMG "./assets/player/player_l_02.xpm"
# define PLAYER_L_04_IMG "./assets/player/player_l_04.xpm"

# define PLAYER_U_01_IMG "./assets/player/player_u_01.xpm"
# define PLAYER_U_02_IMG "./assets/player/player_u_03.xpm"
# define PLAYER_U_03_IMG "./assets/player/player_u_02.xpm"
# define PLAYER_U_04_IMG "./assets/player/player_u_04.xpm"

# define PLAYER_D_01_IMG "./assets/player/player_d_01.xpm"
# define PLAYER_D_02_IMG "./assets/player/player_d_03.xpm"
# define PLAYER_D_03_IMG "./assets/player/player_d_02.xpm"
# define PLAYER_D_04_IMG "./assets/player/player_d_04.xpm"

# define PLAYER_DEATH_01_IMG "./assets/player/player_death_01.xpm"
# define PLAYER_DEATH_02_IMG "./assets/player/player_death_03.xpm"
# define PLAYER_DEATH_03_IMG "./assets/player/player_death_02.xpm"
# define PLAYER_DEATH_04_IMG "./assets/player/player_death_04.xpm"

#endif