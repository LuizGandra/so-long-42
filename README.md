# So Long - A 2D Arcade Game

So Long is a project from the [42 São Paulo](https://www.42sp.org.br/) Common Core curriculum. It involves creating a 2D game using the MiniLibX library, where a player navigates a map to collect items and reach an exit.

| ![bonus](https://github.com/user-attachments/assets/24f64657-8ff2-4253-8d9f-325133220f92) |
|:--:|
| *./so_long_bonus running!* |

My implementation draws inspiration from the classic **Pac-Man arcade game**. Sprites were sourced from [The Spriters Resource](https://www.spriters-resource.com/arcade/pacman/) and adapted using Aseprite, a paid pixel art software, to adapt animations and fit the game design.

![42 São Paulo](https://img.shields.io/badge/42-São_Paulo-black?style=flat-square&logo=42)

## About 42

[42 São Paulo](https://www.42sp.org.br/) is a tuition-free, global coding school focused on peer-to-peer learning and project-based education. This project introduces graphics programming and game development in C.

## Project Overview

| ![mandatory](https://github.com/user-attachments/assets/08f2da56-1c81-43d4-9e88-00763ed155c8) |
|:--:|
| *./so_long running!* |

So Long implements a simple 2D game. The player moves through a map, collecting all items before exiting. It’s divided into:
- **Mandatory Part**: A basic game with player movement, movement counting, item collection, and exit functionality, using a rectangular map with walls, a player, collectibles, and an exit.
- **Bonus Part**: An enhanced version with additional features such as enemies, animations and movement count directly on the game screen.

### Key Features

- Player navigates the map using the arrow keys or W, A, S and D, collecting items to unlock the exit.
- Validates map integrity: rectangular shape, surrounded by walls, contains one player, one exit, and at least one collectible.
- Displays move count in the shell upon each movement.
- Uses MiniLibX for rendering graphics and handling events.
- Bonus:
  - Displays the player's move count directly in the game window.
  - Adds immobile enemies to the game (as a personal extra, I added a variety of enemies based on the original Pac-Man).
  - Adds animations to the player and enemies..

### Restrictions

- Written in C, compliant with the 42 Norm.
- No unexpected crashes (e.g., segmentation faults).
- No memory leaks from heap allocations.
- Compiled with `-Wall -Wextra -Werror`.
- Requires valid `.ber` map files; invalid maps trigger an error message.

## Getting Started

### Prerequisites

- C compiler (e.g., `clang`).
- `make` utility.
- `libft` library in `libs/libft`.
- [MiniLibX](https://github.com/42paris/minilibx-linux) library in `libs/mlx` (Linux version).
- X11 development libraries (`libxext-dev`, `libx11-dev`).

### How to Build and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/LuizGandra/so-long-42.git
   cd so-long-42

2. Build the mandatory part:

   ```bash
   make

3. Run the game with a `.ber` map file:

   ```bash
   ./so_long maps/<map_name>.ber

4. Build the bonus part (optional):

   ```bash
   make bonus

5. Run the bonus game:

   ```bash
   ./so_long_bonus maps/valid_map_bonus.ber

#### Additional commands

- `make clean`: remove object files.
- `make fclean`: remove `libft.a` and object files.
- `make re`: rebuild everything.

## Project Structure

- `includes/so_long.h`: header for mandatory part.
- `src/*.c`: source files for so_long (e.g., main.c, map.c, render.c).
- `maps/*.ber`: pre-made map files for testing.
- `bonus/includes/so_long_bonus.h`: header for bonus part.
- `bonus/src/*.c`: source files for so_long_bonus (e.g., main_bonus.c, animations_bonus.c).
- `Makefile`: compilation automation.
- `libs/libft/`: directory for the libft library.
- `libs/mlx/`: directory for MiniLibX.

## License

This project is part of the 42 curriculum and intended for educational use.
