NAME := libft.a
CFLAGS := -Wall -Werror -Wextra
ARFLAGS := -rcs
HEADERS := libft.h get_next_line_bonus.h
SOURCES := \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
get_next_line_bonus.c get_next_line_utils_bonus.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(MAKE) -C ft_printf
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C ft_printf clean
	@$(RM) $(OBJECTS)

fclean: clean
	@$(MAKE) -C ft_printf fclean
	@$(RM) $(NAME)

re: fclean all
	$(MAKE) -C ft_printf re

norm:
	@norminette -R CheckForbiddenSourceHeader

.PHONY: all clean fclean re norm
