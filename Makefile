# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 16:25:15 by mghalmi           #+#    #+#              #
#    Updated: 2023/01/22 18:57:59 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAMEB = pipex_bonus

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADER = pipex.h

SRC = pipex.c utils.c ft_split.c

SRCB = pipex_bonus.c utils.c ft_split.c

OBJ = $(SRC:c=o)

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJB)
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJB)


clean:
	rm -f $(OBJ) $(OBJB)

fclean:
	rm -f $(OBJ) $(OBJB)
	rm -f $(NAME) $(NAMEB) bonus

re: fclean all

.PHONY: clean fclean re bonus