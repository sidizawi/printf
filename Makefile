# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szawi <szawi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 18:12:06 by szawi             #+#    #+#              #
#    Updated: 2021/06/05 20:45:35 by szawi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = libftprintf.a

SRCS	= ft_printf.c utils/ft_general.c utils/ft_general2.c utils/ft_type_str.c \
		utils/ft_type_char.c utils/ft_type_hex.c utils/ft_type_int.c \
		utils/ft_type_pointer.c utils/ft_type_percent.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) :	$(OBJS)
	make -C libft
	cp -p libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all :	$(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C libft

fclean :	clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
