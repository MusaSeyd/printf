# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 19:23:35 by fcelesti          #+#    #+#              #
#    Updated: 2021/11/27 18:23:30 by fcelesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_putnbr.c ft_putstr.c 
			

HEADER	=	ft_printf.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

.PHONY	:	all	clean	fclean	re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
		ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@$(RM) $(NAME)

re		:	fclean all