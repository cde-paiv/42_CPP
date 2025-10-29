# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 17:13:41 by cde-paiv          #+#    #+#              #
#    Updated: 2025/09/10 17:43:35 by cde-paiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ZombieHorde
SRC = main.cpp zombieHorde.cpp Zombie.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all