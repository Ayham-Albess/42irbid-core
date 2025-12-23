NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_str.c ft_printf_int.c \
       ft_printf_point.c ft_printf_hex.c ft_printf_helper.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
