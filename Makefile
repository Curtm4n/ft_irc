# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 15:24:20 by cdapurif          #+#    #+#              #
#    Updated: 2023/01/12 15:46:28 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ft_irc.cpp

OBJS = $(addprefix src/, $(SRC:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $@ $<

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

show:
	@echo OBJS = $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re