# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 22:11:37 by trietpham         #+#    #+#              #
#    Updated: 2025/02/21 04:58:29 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := ft_printf.c	\
		ft_putchar.c	\
		ft_puthex.c	\
		ft_putnbr.c	\
		ft_putpointer.c	\
		ft_putstr.c	\
		ft_putui.c	

OBJ := $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	ar	rcs	$(NAME)	$(OBJ)

%.o:	%.c
	$(CC) $(CFLAGS)	-c	$<	-o	$@

clean:
	rm	-f	$(OBJ)

fclean: clean
	rm	-f	$(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re
	
