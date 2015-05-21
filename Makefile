# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 18:02:43 by jpiniau           #+#    #+#              #
#    Updated: 2015/05/21 18:42:24 by jpiniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

FLAGS = -Wall -Wextra -Werror

INCLUDES = libft/includes

SRC = main.c\
	  solu.c\
	  simply.c\
	  get_discriminant.c\
	  pow_max.c

OBJ = $(SRC:.c=.o)

all : lib $(NAME)

lib :
	@echo "creation de la libft"
	@make -C libft/

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $^ -L libft/ -lft

%.o : %.c poly.h
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES)

clean :
	rm -fr *.o

fclean : clean
		rm -fr $(NAME)

re : fclean all
