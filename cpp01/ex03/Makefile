# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/24 15:01:06 by cde-paiv          #+#    #+#              #
#    Updated: 2025/09/24 19:21:14 by cde-paiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Weapon
SRC = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all