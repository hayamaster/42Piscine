# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 20:53:16 by donglee2          #+#    #+#              #
#    Updated: 2023/01/29 20:39:49 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/main.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
 
clean:
	$(RM) $(OBJS)
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all