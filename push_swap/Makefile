NAME = push_swap
CC = cc
CFLAGS  = -Wall -Wextra -Werror 
INCLUDES = -I include

SRC = push_swap.c\
      push_swap2.c\
      validation.c\
      utils.c\
      simple.c\
      medium.c\
      complex.c\
      sort.c\
      operations.c\
      operations2.c\
      operations3.c\
      bench.c\
      ft_atoi.c\
      ft_split.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

