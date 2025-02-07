CFLAGS := -Wall -Werror -Wextra
ARFLAGS := -rcs
RM := rm -rf
HEADERS := ft_printf_bonus.h
SOURCES := \
	ft_printf_bonus.c utils_bonus.c ft_putaddress_bonus.c ft_puthex_bonus.c \
	ft_putchar_bonus.c ft_putnbr_bonus.c ft_putstr_bonus.c
OBJ_DIR := objects
OBJECTS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(OBJ_DIR) $(OBJECTS)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR)

re: clean all

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all clean fclean re norm