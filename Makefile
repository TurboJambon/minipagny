# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/05 14:20:07 by dchirol           #+#    #+#              #
#    Updated: 2017/05/05 14:20:16 by dchirol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc -o $@ $^ libft.a

clean:
	/bin/rm -f $(OBJ)

fclean: clean


re : clean all