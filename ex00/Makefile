# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lformank <lformank@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 16:46:14 by lformank          #+#    #+#              #
#    Updated: 2026/01/31 17:08:08 by lformank         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = c++
FLAGS = -Wall -Wextra -Werror -Iinclude -std=c++98 -g
SRCS = main.cpp Fixed.cpp
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
SRC_DIR = src/
OBJ_DIR = obj/
NAME = fixed

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(C) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(C) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re