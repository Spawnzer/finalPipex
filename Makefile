# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:33:27 by adubeau           #+#    #+#              #
#    Updated: 2021/12/15 17:14:55 by adubeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	pipex

SRCS		= 	srcs/pipex.c \
			srcs/ft_exec.c \
			srcs/ft_split.c \
			srcs/ft_utils.c


OBJS		= $(SRCS:.c=.o)
RM			= rm -rf
EXEC		= gcc -o
FLAGS		= -Wall -Werror -Wextra -c -g
INCS		= ./includes
CC			= gcc
CP			= cp

.c.o:
	$(CC) $(FLAGS) $< -o $(<:.c=.o) -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(EXEC) $(NAME) $(OBJS) $(LIB)

clean:
	@clear all
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM)

re: fclean all clean

.PHONY: all clean fclean re .c.o
