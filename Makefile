NAME := so_long
CC := clang
CFLAGS := -Wall -Werror -Wextra
SOURCES_DIR := src
HEADERS := $(SOURCES_DIR)/so_long.h
LIBS_DIR := libs
LIBFT := $(LIBS_DIR)/libft
MLX := mlx
INCLUDES := -I/usr/include -I$(LIBS_DIR)/$(MLX) -I$(LIBFT)
LIBS := -L$(LIBS_DIR)/$(MLX) -l$(MLX)_Linux -L/usr/lib -L$(LIBFT) -lft -lXext -lX11 -lm -lz
SOURCES := \
	$(SOURCES_DIR)/main.c $(SOURCES_DIR)/hooks.c $(SOURCES_DIR)/map.c \
	$(SOURCES_DIR)/render.c $(SOURCES_DIR)/player_actions.c \
	$(SOURCES_DIR)/utils.c
OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(OBJECTS) $(LIBS) -O0 -g3 -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -O0 -g3 -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all clean fclean re norm