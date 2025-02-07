NAME := so_long
CC := clang
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf
SRC_DIR := src
HEADERS := $(SRC_DIR)/so_long.h
LIBS_DIR := libs
LIBFT := $(LIBS_DIR)/libft
MLX := mlx
INCLUDES := -I/usr/include -I$(LIBS_DIR)/$(MLX) -I$(LIBFT)
LIBS := -L$(LIBS_DIR)/$(MLX) -l$(MLX)_Linux -L/usr/lib -L$(LIBFT) -lft -lXext -lX11 -lm -lz
SOURCES := \
	main.c hooks.c map.c render.c player_actions.c utils.c errors.c
SOURCES := $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJ_DIR := objects
OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))

all: $(OBJ_DIR) $(NAME)

# TODO remove -O0 -g3
$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(OBJECTS) $(LIBS) -O0 -g3 -o $(NAME)

# TODO remove -O0 -g3
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -O0 -g3 -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all clean fclean re norm