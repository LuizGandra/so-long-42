NAME := so_long
CC := clang
CFLAGS := -Wall -Werror -Wextra
HEADERS := so_long.h
LIBFT := libft
MLX := mlx
INCLUDES := -I/usr/include -I$(mlx) -I$(LIBFT)/$(LIBFT)
LIBS := -L$(MLX) -l$(MLX)_Linux -L/usr/lib -I$(MLX) -lXext -lX11 -lm -lz $(LIBFT)/$(LIBFT).a
SOURCES := main.c
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