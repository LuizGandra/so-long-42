NAME := so_long
NAME_BONUS := so_long_bonus
CC := clang
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf
SRC_DIR := src
BONUS_DIR := src_bonus
HEADERS := $(SRC_DIR)/so_long.h
HEADERS_BONUS := $(BONUS_DIR)/so_long_bonus.h $(BONUS_DIR)/so_long_sprites_bonus.h
LIBS_DIR := libs
LIBFT := $(LIBS_DIR)/libft
MLX := mlx
INCLUDES := -I/usr/include -I$(LIBS_DIR)/$(MLX) -I$(LIBFT)
LIBS := -L$(LIBS_DIR)/$(MLX) -l$(MLX)_Linux -L/usr/lib -L$(LIBFT) -lft -lXext -lX11 -lm -lz
SRCS := \
	main.c hooks.c map.c render.c controller.c statics.c utils.c errors.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
SRCS_BONUS := \
	main_bonus.c hooks_bonus.c \
	map_bonus.c map_utils_bonus.c \
	render_bonus.c render_utils_bonus.c \
	controller_bonus.c statics_bonus.c \
	load_sprites_bonus.c load_sprites_utils_bonus.c \
	animations_bonus.c game_over_bonus.c \
	general_utils_bonus.c clean_bonus.c errors_bonus.c
SRCS_BONUS := $(addprefix $(BONUS_DIR)/, $(SRCS_BONUS))
OBJ_DIR := objects
OBJ_BONUS_DIR := objects_bonus
OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJECTS_BONUS := $(addprefix $(OBJ_BONUS_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))
VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
GDB = gdb
GDB_FLAGS = -tui -args

all: $(LIBFT) $(OBJ_DIR) $(NAME)

# TODO remove -O0 -g3
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LIBS) -O0 -g3 -o $@

# TODO remove -O0 -g3
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -O0 -g3 -c $< -o $@

bonus: $(LIBFT) $(OBJ_BONUS_DIR) $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $^ $(LIBS) -O0 -g3 -o $@

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -O0 -g3 -c $< -o $@

$(LIBFT):
	$(MAKE) -C $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_BONUS_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

valgrind: all
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME) $(MAP)

valgrind_bonus: bonus
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME_BONUS) $(MAP)

gdb: all
	$(GDB) $(GDB_FLAGS) ./$(NAME) $(MAP)

gdb_bonus: bonus
	$(GDB) $(GDB_FLAGS) ./$(NAME_BONUS) $(MAP)

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all bonus $(LIBFT) clean fclean re valgrind valgrind_bonus gdb_bonus norm