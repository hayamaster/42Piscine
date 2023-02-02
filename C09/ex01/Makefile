CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INCLUDE = includes

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

$(NAME) : $(OBJS)
	ar rc $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
