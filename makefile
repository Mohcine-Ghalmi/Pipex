# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:30:19 by mghalmi           #+#    #+#              #
#    Updated: 2023/01/20 15:05:21 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_split.c   ft_strjoin.c  ft_strncmp.c utils.c pipex.c ft_pustr_fd.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) pipex.h
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) pipex.c $(NAME) -o pipex
	
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) pipex

re : fclean all