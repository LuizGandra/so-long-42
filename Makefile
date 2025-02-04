NAME := so_long
CC := clang
CFLAGS := -Wall -Werror -Wextra
SOURCES_DIR := src
HEADERS := $(SOURCES_DIR)/so_long.h
LIBS_DIR := libs
LIBFT := $(LIBS_DIR)/libft
MLX := mlx
INCLUDES := -I/usr/include -I$(LIBS_DIR)/$(MLX) -I$(LIBFT)
# TODO check if -I is necessary in LIBS for linker
LIBS := -L$(LIBS_DIR)/$(MLX) -l$(MLX)_Linux -L/usr/lib -L$(LIBFT) -lft -lXext -lX11 -lm -lz
SOURCES := $(SOURCES_DIR)/main.c $(SOURCES_DIR)/hooks.c
OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(OBJECTS) $(LIBS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

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