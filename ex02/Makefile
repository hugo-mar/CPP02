# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 17:32:48 by hugo-mar          #+#    #+#              #
#    Updated: 2025/07/11 19:13:43 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS_PATH = ./srcs/

SRCS = $(SRCS_PATH)Fixed.cpp $(SRCS_PATH)main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(ARCHIVE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re