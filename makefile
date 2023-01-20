# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:30:19 by mghalmi           #+#    #+#              #
#    Updated: 2023/01/20 13:14:32 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
Rm = -rf
SRCS = ft_split.c   ft_strjoin.c  ft_strncmp.c utils.c pipex.c
INCLUDE = pipex.h

all : $(NAME)

SRO : $(SRCS:.c=.o)

%(NAME) : $(SRO) $(INCLUDE)
	ar rc $(NAME) $(SRO)
	$(CC) $(CFLAG) pipex.c $(NAME) -o pipex

clean :
	rm -rf $(SRO)

fclean : clean
	rm -rf $(NAME)

re :
	fclean all