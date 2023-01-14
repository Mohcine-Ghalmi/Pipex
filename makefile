# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:30:38 by mghalmi           #+#    #+#              #
#    Updated: 2023/01/13 18:46:29 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PIPEX
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC =


$(NAME) : printf
	gcc $(src) ft_printf/libftprintf.a 
	

printf :
	make -C ft_printf