NAME := so_long

CC := clang
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf

INCLUDES_DIR := includes
LIBS_DIR := libs
MLX := mlx
LIBFT := $(LIBS_DIR)/libft
LIBS := \
	-L$(LIBS_DIR)/$(MLX) -l$(MLX)_Linux -L/usr/lib -L$(LIBFT) -lft -lXext -lX11
INCLUDES := -I/usr/include -I$(INCLUDES_DIR) -I$(LIBS_DIR)/$(MLX) \
	-I$(LIBFT)/include -I$(LIBFT)/ft_printf/include

HEADERS := $(INCLUDES_DIR)/so_long.h

SRC_DIR := src
SRCS := \
	main.c hooks.c map.c render.c controller.c statics.c utils.c errors.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR := objects
OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

NAME_BONUS := so_long_bonus

BONUS_DIR := bonus

INCLUDES_BONUS := -I/usr/include -I$(BONUS_DIR)/$(INCLUDES_DIR) \
	-I$(LIBS_DIR)/$(MLX) -I$(LIBFT)/include -I$(LIBFT)/ft_printf/include

HEADERS_BONUS := $(BONUS_DIR)/$(INCLUDES_DIR)/so_long_bonus.h \
	$(BONUS_DIR)/$(INCLUDES_DIR)/so_long_sprites_bonus.h

SRC_DIR_BONUS := $(BONUS_DIR)/$(SRC_DIR)
SRCS_BONUS := \
	main_bonus.c hooks_bonus.c \
	map_bonus.c map_utils_bonus.c \
	render_bonus.c render_utils_bonus.c \
	controller_bonus.c statics_bonus.c \
	load_sprites_bonus.c load_sprites_utils_bonus.c \
	animations_bonus.c animations_utils_bonus.c game_over_bonus.c \
	general_utils_bonus.c clean_bonus.c errors_bonus.c

SRCS_BONUS := $(addprefix $(SRC_DIR_BONUS)/, $(SRCS_BONUS))

OBJ_DIR_BONUS := $(BONUS_DIR)/$(OBJ_DIR)
OBJECTS_BONUS := $(addprefix $(OBJ_DIR_BONUS)/, $(notdir $(SRCS_BONUS:.c=.o)))

VALGRIND := valgrind
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

GDB := gdb
GDB_FLAGS := -tui -args

all: $(MLX) $(LIBFT) $(OBJ_DIR) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(MLX) $(LIBFT) $(OBJ_DIR_BONUS) $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $@

$(MLX):
ifeq ($(wildcard $(LIBS_DIR)/$(MLX)/libmlx_Linux.a), )
	$(MAKE) -C $(LIBS_DIR)/$(MLX)
endif

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR_BONUS):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBS_DIR)/$(MLX) clean
	$(RM) $(OBJ_DIR) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

vg: all
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME) $(MAP)

vg_bonus: bonus
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME_BONUS) $(MAP)

gdb: all
	$(GDB) $(GDB_FLAGS) ./$(NAME) $(MAP)

gdb_bonus: bonus
	$(GDB) $(GDB_FLAGS) ./$(NAME_BONUS) $(MAP)

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all bonus $(LIBFT) clean fclean re vg vg_bonus gdb_bonus norm