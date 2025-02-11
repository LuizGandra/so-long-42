/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprites_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:25:28 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/11 17:22:03 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_SPRITES_BONUS_H
# define SO_LONG_SPRITES_BONUS_H

// * IMAGES SIZE
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

// * MAP SPRITES
# define BACKGROUND_IMG "./assets/map/background.xpm"
# define WALL_IMG "./assets/map/wall.xpm"
# define COLLECTIBLE_IMG "./assets/map/collectible.xpm"
# define EXIT_IMG "./assets/map/exit.xpm"

// * UI SPRITES
# define MOVEMENT_LOG_BG_IMG "./assets/ui/movement_log_bg.xpm"

// * STATIC SPRITES INDEXES
# define BACKGROUND_INDEX 0
# define WALL_INDEX 1
# define COLLECTIBLE_INDEX 2
# define EXIT_INDEX 3
# define MOVEMENT_LOG_BG_INDEX 4

// * SPRITES PATH
# define BASE_PATH "./assets/"
# define PLAYER_PATH "./player/player_"
# define ENEMY_PATH "./enemies/enemy_"

// * ENEMY INDEXES
# define ENEMY_RED_INDEX 0
# define ENEMY_BLUE_INDEX 1
# define ENEMY_PINK_INDEX 2
# define ENEMY_YELLOW_INDEX 3

#endif